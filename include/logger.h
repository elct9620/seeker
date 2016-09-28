// Copyright 2016 Zheng Xian Qiu

#include <SDL2/SDL_log.h>
#include<string>

using std::string;

class Logger {
  public:
    static void Verbose(string format, ...);
    static void Info(string format, ...);
    static void Debug(string format, ...);
    static void Error(string format, ...);
    static void Critical(string format, ...);
    static void Warn(string format, ...);
};
