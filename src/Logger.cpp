// Copyright 2016 Zheng Xian Qiu

#include "logger.h"

void Logger::Info(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_INFO,
                  format.c_str(),
                  args);
  va_end(args);
}

void Logger::Verbose(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_VERBOSE,
                  format.c_str(),
                  args);
  va_end(args);
}

void Logger::Debug(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_DEBUG,
                  format.c_str(),
                  args);
  va_end(args);
}

void Logger::Warn(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_WARN,
                  format.c_str(),
                  args);
  va_end(args);
}

void Logger::Error(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_ERROR,
                  format.c_str(),
                  args);
  va_end(args);
}

void Logger::Critical(string format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_CRITICAL,
                  format.c_str(),
                  args);
  va_end(args);
}
