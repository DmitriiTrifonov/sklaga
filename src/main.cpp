#include <iostream>
#include <SDL.h>

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "Hello" << std::endl;
    SDL_Quit();
}