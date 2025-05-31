#pragma once

#include <Managers/Graphics.hpp>
#include <cstring>
#include <iostream>

#define FONT "assets/Fonts/empty.ttf"
#define VIDEO_W 1920
#define VIDEO_H 1080
#define FRAMERATE 120

namespace Managers {
    float Graphics::dt = 0.0;
    //Creation of game window
    Graphics::Graphics() :
    window(new sf::RenderWindow(sf::VideoMode(VIDEO_W,VIDEO_H), "Jogo", sf::Style::Fullscreen)),
    view(sf::Vector2f(VIDEO_W / 2, VIDEO_H / 2), sf::Vector2f(VIDEO_W, VIDEO_H)),
    textureMap(),
    clock(){
        font = NULL;
    }

    //Graphics Destructor
    Graphics::~Graphics() {
        std::map<const char*, sf::Texture*>::iterator it; //iterador para texturas
        for (it = textureMap.begin(); it != textureMap.end(); ++it)
            delete(it->second);
        delete(window); //finish game
    }

    //Renders a body in the screen
    void Graphics::render(sf::RectangleShape* body) {
        window->draw(*body);
    }

    //Renders text in the screen
    void Graphics::render(sf::Text* text) {
        window->draw(*text);
    }

    //Display all things that were rendered
    void Graphics::display() {
        if(isWindowOpen()){
            window->display();
        }
    }

    //Clear the window
    void Graphics::clear() {
        if(isWindowOpen()){
            window->clear();
        }
    }

    //Distribute pointer to window
    sf::RenderWindow* Graphics::getWindow() const {
        return window;
    }

    //Returns the state of the window (open or not)
    bool Graphics::isWindowOpen() const {
        return window->isOpen();
    }

    //Calls the function to close window on SFML
    void Graphics::closeWindow() {
        window->close();
    }

    //Handles resizes
    void Graphics::handleWindowResize() {
        float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
        view.setSize(sf::Vector2f(VIDEO_H * aspectRatio, VIDEO_H));
        window->setView(view);
    }

    //Returns window size
    sf::Vector2u Graphics::getWindowSize() const {
        return window->getSize();
    }

    //Updates view position
    void Graphics::centerView(Math::CoordsF position) {
        view.setCenter(sf::Vector2f(position.x, position.y));
        window->setView(view);
    }

    //Returns a pointer to a texture, so that an Entity can use it
    sf::Texture* Graphics::loadTexture(const char* path) {
        //Searches the texture map for an existing texture with that path
        std::map<const char*, sf::Texture*>::iterator it = textureMap.begin();
        while (it != textureMap.end()){
            if (!strcmp(it->first, path)) //strcmp returns 0 for matching strings, anything else if not
                return it->second; //if it matches, return the file
            it++;
        }

        //if it didn't find it, then:
        sf::Texture* texture = new sf::Texture();

        if(!texture->loadFromFile(path)){ //if it fails to open
            std::cout << "Couldn't load image file from:" << path << std::endl;
            exit(1); //throw error
        }

        //if it's ok:
        textureMap.insert(std::pair<const char*, sf::Texture*>(path, texture));
        return texture; //and we're happy
    }

    //Returns a pointer to a font, to write stuff
    sf::Font* Graphics::getFont() {
        //"same" logic
        if(!font){
            font = new sf::Font();
            if (!font->loadFromFile(FONT)){
                std::cout << "Couldn't load font file from: " << FONT << std::endl;
                exit(1); //throw error
            }
        }
        return font;
    }

    //Updates the game clock
    void Graphics::updateDeltaTime() {
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}
