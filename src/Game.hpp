#ifndef GAME_HPP  
#define GAME_HPP

#include "State.hpp"

class Game {
private:
    // Variables 
    sf::RenderWindow *window;
    sf::Event sfEvent;
  
    sf::Clock dtClock;
    float dt; // delta time
  
    // Initialization
    void initWindow();

public:
    Game();
    virtual ~Game();

    // Functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

#endif // GAME_HPP
