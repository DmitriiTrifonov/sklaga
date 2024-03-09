#include "window.h"
#include <string>

Window::Window(int width, int height, const std::string& title) {
    this->width = width;
    this->height = height;
    this->title = title;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );

        return;
    } else {
        window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    }
}

SDL_Window *Window::getWindow() {
    return this->window;
}

Window::~Window() {
    SDL_DestroyWindow(this->getWindow());
}

int Window::getWidth() const {
    return this->width;
}

int Window::getHeight() const {
    return this->height;
}

std::string Window::getTitle() {
    return title;
}