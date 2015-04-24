#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderable {
	//The image we will load and show on the screen
public:
	SDL_Surface 	*screenSurface;
	SDL_Surface 	*surface;
	SDL_Rect 		rectFrom;
	SDL_Rect 		rectTo;

public:

	Renderable(SDL_Surface *screenSurface, std::string path) {
		this->screenSurface = screenSurface;
		this->surface = loadSurface(path);
	}

	~Renderable() {
		SDL_FreeSurface(this->surface);
	}

	void print() {
    	SDL_BlitSurface(surface, &rectFrom, screenSurface, &rectTo);
	}

	virtual void update() = 0;

	void changePos(int x, int y) {
		this->rectTo.x = x;
		this->rectTo.y = y;
	}

	SDL_Surface* loadSurface(std::string path) {
	    //The final optimized image
	    SDL_Surface* optimizedSurface = NULL;

	    //Load image at specified path
	    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	    if(loadedSurface == NULL) {
	        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	    } else {
	        //Convert surface to screen format
	        optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
	        if(optimizedSurface == NULL) {
	            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	        }
	        //Get rid of old loaded surface
	        SDL_FreeSurface(loadedSurface);
	    }

	    return optimizedSurface;
	}

};

#endif