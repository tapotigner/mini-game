#ifndef __CURSOR_HPP__
#define __CURSOR_HPP__

#include <stdio.h>
#include <string>
#include "Renderable.hpp"

class Cursor : public Renderable {

public:
	
	Cursor(SDL_Surface *s) : Renderable(s, "src/images/cursor.png") {
		this->rectFrom.x = 0;
		this->rectFrom.y = 0;
		this->rectFrom.w = 64;
		this->rectFrom.h = 64;
		this->rectTo.w = 64;
		this->rectTo.h = 64;
	}

	void update() {}

};

#endif