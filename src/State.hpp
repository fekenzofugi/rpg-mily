#ifndef STATE_HPP
#define STATE_HPP 

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
private:
    std::vector<sf::Texture> textures;
public:
    State();
    virtual ~State();

    virtual void update() = 0; // pure virtual, need to be defined on the child class
    virtual void render() = 0;
};

#endif // STATE_HPP
