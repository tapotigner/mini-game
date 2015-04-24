#ifndef __DISPLAYMANAGER_HPP__
#define __DISPLAYMANAGER_HPP__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class DisplayManager {

public:
	//Screen dimension constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	// The window we'll be rendering to
	SDL_Window* window;
	// The surface contained by the window
	SDL_Surface* screenSurface;

public:

	bool init() {
	    // Initialization flag
	    bool success = true;
	    // Initialize SDL
	    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	        success = false;
	    }
	    else {
	        // Create window
	        window = SDL_CreateWindow("PickCoins", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	        if(window == NULL) {
	            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	            success = false;
	        } else {
	            // Configure the window
	            // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	            SDL_ShowCursor(SDL_DISABLE);

	            // Initialize PNG loading
	            int imgFlags = IMG_INIT_JPG|IMG_INIT_PNG;
	            if (!(IMG_Init(imgFlags) & imgFlags)) {
	                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	                success = false;
	            } else {
	                // Get window surface
	                screenSurface = SDL_GetWindowSurface(window);
	            }
	        }
	    }
	    return (success);
	}

	void close() {
	    // Destroy window
	    SDL_DestroyWindow(window);
	    window = NULL;
	    // Quit SDL subsystems
	    SDL_Quit();
	}

	DisplayManager() {

	}

	~DisplayManager() {
		close();
	}
};

#endif