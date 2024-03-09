#ifndef SKLAGA_WINDOW_H
#define SKLAGA_WINDOW_H
#include "SDL.h"
#include <string>

class Window {
private:
    int width;
    int height;
    std::string title;
    SDL_Window* window;
public:
    Window(int width, int height, const std::string& title);

    int getWidth() const;
    int getHeight() const;
    std::string getTitle();

    SDL_Window* getWindow();

    ~Window();
};


#endif //SKLAGA_WINDOW_H
