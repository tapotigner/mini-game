#ifndef __BACKGROUND_HPP__
#define _BACKGROUND_HPP__

class Background{

private:
	SDL_Surface 	*screenSurface;

public:
	
	Background(SDL_Surface *screenSurface) {
		this->screenSurface = screenSurface;
	}

	void print() {
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 50, 50, 50));
	}

};

#endif