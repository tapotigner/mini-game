#ifndef __COIN_HPP__
#define __COIN_HPP__

#include <stdio.h>
#include <iostream>
#include <string>
#include "Renderable.hpp"
#include "Utils.hpp"

class Coin : public Renderable {

private:

	int spriteWidth = 64;
	int spriteHeight = 64;
	int isPicked = false;

public:
	
	Coin(SDL_Surface *s) : Renderable(s, "src/images/coins.png") {
		this->rectFrom.x = 0;
		this->rectFrom.y = 0;
		this->rectFrom.w = spriteWidth;
		this->rectFrom.h = spriteHeight;
		this->rectTo.x = intGenerator(0, 800 - 64);
		this->rectTo.y = intGenerator(0, 600 - 64);
		this->rectTo.w = spriteWidth;
		this->rectTo.h = spriteHeight;
	}

	void updateSprite() {
		if (!isPicked) {
			this->rectFrom.x += 64;
			this->rectFrom.y += 64;
			if (this->rectFrom.x == 512) {
				this->rectFrom.x = 0;
			}
			if (this->rectFrom.y == 512) {
				this->rectFrom.y = 0;
			}
		} else {
			this->rectFrom.x = 0;
			this->rectFrom.y = 512;
			this->rectFrom.w = 32;
			this->rectFrom.h = 32;
		}
	}

	void update() {
		updateSprite();
	}

	bool click(int x, int y) {
		std::cout << "Test coin.. !" << std::endl;
		if (rectTo.x < x && x < rectTo.x + rectTo.w
			&& rectTo.y < y && y < rectTo.y + rectTo.h
			&& !isPicked) {
			isPicked = true;
			return true;
		}
		return false;
	}

};

#endif