#include "GameManager.hpp"
#include "DisplayManager.hpp"

int main(int argc, char* args[]) {
    DisplayManager  *displayManager;
    GameManager     *gameManager;

    displayManager = new DisplayManager();
    
    if (displayManager->init()) {
        gameManager = new GameManager(displayManager);
        gameManager->run();
    }
    return (0);
}