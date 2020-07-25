#pragma once
//#include <log4cxx/logger.h>
#include <string>
#include "utils/ilogger.h"

// START Redefince for each paticular logger implementation
class BoostLogger;
typedef BoostLogger ExternalLogger;
typedef std::string LocationInfo;
#define LOCATTION_INFO "blabla"

typedef LogMessage<LocationInfo> LogMessageImpl;

#define CREATE_LOGGERPTR(logger_name)      \
  namespace {                              \
  static std::string logger_(logger_name); \
  }

#define LOG_WITH_LEVEL(logLevel, logEvent)                             \
  do {                                                                 \
    auto location = LOCATTION_INFO;                                    \
    LogMessageImpl message{logger_,                                    \
                           logLevel,                                   \
                           logEvent,                                   \
                           std::chrono::high_resolution_clock::now(),  \
                           location,                                   \
                           std::this_thread::get_id()};                \
    Logger<LocationInfo, ExternalLogger>::instance().PushLog(message); \
  } while (false)

#undef LOG4CXX_TRACE
#define LOG4CXX_TRACE(loggerPtr, logEvent) \
  LOG_WITH_LEVEL(loggerPtr, ::log4cxx::Level::getTrace(), logEvent)
