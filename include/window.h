// Copyright 2016 Zheng Xian Qiu

#include <string>

using std::string;

class Window {

  public:
    Window();

    // Display Information
    static int DISPLAY_INDEX;
    static int getDisplayWidth();
    static int getDisplayHeight();

    static void loadDisplayMode(bool reload = false);

    // Window Manager
    bool create(string title, bool hide = false);
    void destroy();

  private:
    static SDL_DisplayMode displayMode;
    static bool displayModeLoaded;
    SDL_Window *currentWindow;
};
