#include <string>
#include <utility>
#include "SDL.h"
#include "window.h"

void init_window(int width, int height, const std::string& title){
    auto w = new Window(width, height, title);

    //Create window
    SDL_Window* window = w->getWindow();

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    if( window == NULL ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );

        return;
    } else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while(!quit){ while( SDL_PollEvent(&e ) ){ if(e.type == SDL_QUIT ) quit = true; } }
    }

    //Destroy window
    delete(w);

    //Quit SDL subsystems
    SDL_Quit();
}
