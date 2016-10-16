// Copyright 2016 Zheng Xian Qiu

#pragma once

#include<string>
#include "Seeker.h"

#ifndef LOGGER_H_
#define LOGGER_H_

using std::string;

#define LOG(priority, format, ...)              \
  va_list args;                                 \
  va_start(args, format);                       \
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, \
                  SDL_LOG_PRIORITY_##priority,  \
                  format.c_str(),               \
                  args);                        \
  va_end(args);

namespace Seeker {
  class Logger {
    public:
      static void Verbose(string format, ...);
      static void Debug(string format, ...);
      static void Info(string format, ...);
      static void Warn(string format, ...);
      static void Error(string format, ...);
      static void Critical(string format, ...);
  };
}

#endif
