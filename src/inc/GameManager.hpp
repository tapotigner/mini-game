#ifndef __GAMEMANAGER_HPP__
#define __GAMEMANAGER_HPP__

#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

#include "DisplayManager.hpp"
#include "Cursor.hpp"
#include "Background.hpp"
#include "Coin.hpp"

class GameManager {

private:
	std::list<Coin*>	coins = std::list<Coin*>();
	Uint32				currentTime = 0;
	Uint32				coinTime = 0;
	DisplayManager 		*displayManager = NULL;
	SDL_Event 			test_event;
	bool				isRunning = false;
	Cursor 				*cursor = NULL;
	Background 			*background = NULL;
	int 				score = 0;
	bool				testCoin = false;

public:

	GameManager(DisplayManager *dm) {
		this->displayManager = dm;
		isRunning = true;
	}

	~GameManager() {}

	void init() {
		this->cursor = new Cursor(displayManager->screenSurface);
		this->background = new Background(displayManager->screenSurface);
	}


	void events() {
		SDL_PollEvent(&test_event);
		switch (test_event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEMOTION:
				cursor->changePos(test_event.motion.x, test_event.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (test_event.button.button == SDL_BUTTON_LEFT) {
					std::cout << "Click ! :P" << std::endl;
					testCoin = true;
				}
			case SDL_KEYDOWN:
				if (test_event.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
				break;
			default:
				break;
		}
	}

	void popCoin() {
		coins.push_back(new Coin(displayManager->screenSurface));
		std::cout << "New Coin" << std::endl;
	}

	void printCoins() {
		std::list<Coin*>::iterator iter;
		bool result;
		bool isJustDeleted = false;
		iter = coins.begin();

		while(iter != coins.end()) {
			if (testCoin) {
				result = (*iter)->click(test_event.motion.x, test_event.motion.y);
				if (result) {
					//iter = coins.erase(iter);
					(*iter)->rectTo.y = 10;
					(*iter)->rectTo.x = 10 + 32 * score;
					testCoin = false;
					isJustDeleted = true;
					score += 1;
				} else {
				}
			}
			if (isJustDeleted != true) {
			    (*iter)->update();
			    (*iter)->print();
		    } else {
		    	isJustDeleted = false;
		    }
		    iter++;
		}
		testCoin = false;
	}

	void run() {
		int displayTime = 40;
		int lastDisplay = 0;
		init();
		popCoin();
		while (isRunning) {
			currentTime = SDL_GetTicks();
			// Getting inputs
			events();

			if (currentTime - coinTime >= 1000) {
				popCoin();
				coinTime = currentTime;
			}
			if (currentTime - lastDisplay >= displayTime) {
				// Print all game data
				background->print();
				printCoins();
				cursor->print();
				lastDisplay = currentTime;
			}
			// Update the surface
			SDL_UpdateWindowSurface(displayManager->window);
			// Wait a couple of milliseconds in order to not burn your computer :P
			SDL_Delay(0);
		}

	}

};

#endif