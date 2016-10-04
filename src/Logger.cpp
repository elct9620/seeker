// Copyright 2016 Zheng Xian Qiu

#include "Logger.h"

namespace Seeker {
  void Logger::Verbose(string format, ...) {
    LOG(VERBOSE, format)
  }

  void Logger::Info(string format, ...) {
    LOG(INFO, format)
  }

  void Logger::Debug(string format, ...) {
    LOG(DEBUG, format)
  }

  void Logger::Warn(string format, ...) {
    LOG(WARN, format)
  }

  void Logger::Error(string format, ...) {
    LOG(ERROR, format);
  }

  void Logger::Critical(string format, ...) {
    LOG(CRITICAL, format)
  }
}
