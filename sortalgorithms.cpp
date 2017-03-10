#include "sortalgorithms.h"

template<class T>
void ShellSort(T *t, unsigned n)
{
    T buf;
    for( unsigned k = n/2;k>0;k/=2){
        for(unsigned i =k;i<n;i+=1){
            buf= t[i];
            unsigned j;
            for(j=i;j>=k;j-=k){
                if(buf<t[j-k]){
                    t[j]=t[j-k];
                }else break;
            }
            t[j]=buf;
        }
    }
}
