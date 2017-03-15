#ifndef THREADSPATTERNS_H
#define THREADSPATTERNS_H
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include <utility>

#include <map>
#include <list>
#include <vector>
#include <deque>

#include  <algorithm>
//#include <pthread.h>
namespace scheduling{
    template<class Clock>
    class Scheduler{
        typedef Clock clock_type;
        typedef typename clock_type::time_point time_point;
        typedef typename clock_type::duration duration;
        typedef std::function<void()> task_type;
    private:
        /*---------------------------------------------------------------------*/
        struct Task{
            Task(task_type&& task, const time_point& start,const duration& repeat)
                :task(std::move(task)),start(start),repeat(repeat){}
            task_type task;
            time_point start;
            duration repeat;
            bool operator<(const Task& other) const{
                return start< other.start;
            }
        };

        /*---------------------------------------------------------------------*/
    public:
        typedef typename std::list<Task>::iterator task_handle;

    private:
        std::mutex mutex;
        std::condition_variable tasks_updated;

        std::deque<task_handle> todo;
        std::condition_variable modified;

        bool running;
        std::list<Task> tasks;
        std::list<task_handle> handles;

        std::vector<std::thread>  threads;
    public:
        Scheduler(): threads(4){}
        ~Scheduler(){halt();}
        task_handle schedule(task_type&& task
                             , const time_point& start
                             , const duration& repeat=duration::zero()){
            task_handle handle_;
            {
                std::lock_guard<std::mutex> lock(mutex);
                handle_ = tasks.emplace(tasks.end(),std::move(task), start, repeat);
                handles.push_back(handle_);
            }
            tasks_updated.notify_all();
            return handle_;
        }
        task_handle schedule(task_type&& task
                             , const duration& delay=duration::zero()
                             , const duration& repeat=duration::zero()){
        return schedule(std::move(task),clock_type::now()+delay,repeat);

        }

        void unschedule(const task_handle& handle){
            {
                std::lock_guard<std::mutex> lock(mutex);
                auto handle_it = std::find(handles.begin(),handles.end(),handle);
                if(handle_it != handles.end()){
                    tasks.erase(handle);
                    todo.remove(handle);
                    handles.erase(handle_it);
                }
            }
            tasks_updated.notify_all();
        }

        void clear(){
            {
                std::lock_guard<std::mutex> lock(mutex);
                tasks.clear();
                handles.clear();
            }
            tasks_updated.notify_all();
        }
        void run(){
            {
                std::lock_guard<std::mutex> lock(mutex);
                if(running) return;

                running = true;
                for( auto& t : threads){
                    t = std::thread([this]{this->loop();});
                }
            }
            while(true){
                std::unique_lock<std::mutex> ulock(mutex);
                if(!running) break;
                auto task_it = min_element(tasks.begin(),tasks.end());
                time_point next_task = task_it == tasks.end() ?
                            clock_type::time_point::max() : task_it->start;
                if(tasks_updated.wait_until(ulock,next_task) == std::cv_status::timeout){
                    if( task_it->repeat != clock_type::duration::zero() ){
                        task_it->start += task_it->repeat;
                    }else{
                        handles.remove(task_it);
                        tasks.erase(task_it);
                    }
                    todo.push_back(task_it);
                    modified.notify_all();
                }
            }
            for(auto& t : threads){
                t.join();
            }
        }

        void halt(){
            {
                std::lock_guard<std::mutex> lock(mutex);
                if(!running) return;
                running = false;
            }
            tasks_updated.notify_all();
            modified.notify_all();
        }
    private:
        void loop(){
            while(true){
                std::function<void()> f;
                {
                    std::unique_lock<std::mutex> ulock(mutex);
                    while(todo.empty() && running){
                        modified.wait(ulock);
                    }
                    if(!running)return;
                     f = todo.front()->task;
                     todo.pop_front();
                }
                f();
            }
        }

    };

}
#endif // THREADSPATTERNS_H
