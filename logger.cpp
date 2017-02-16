#include "logger.h"

Logger::Logger(LoggerImpl *p): pimpl(p)
{
}

Logger::~Logger()
{
 delete pimpl;
}
