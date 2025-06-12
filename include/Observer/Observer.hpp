#pragma once
#include <SFML/Graphics.hpp>

namespace Game::Observer {

    class Observer {
    private:
        bool active;

    public:
        Observer() : active(true) {}
        virtual ~Observer() {}

        void setActive(bool isActive) { this->active = isActive; }
        const bool isActive() const { return active; }

        virtual void notifyKeyPressed(sf::Keyboard::Key key) {}
        virtual void notifyKeyReleased(sf::Keyboard::Key key) {}
        virtual void notifyMouseMoved(const sf::Event::MouseMoveEvent& mouse) {}
        virtual void notifyMouseButtonPressed(const sf::Event::MouseButtonEvent& mouse) {}
        virtual void notifyMouseButtonReleased(const sf::Event::MouseButtonEvent& mouse) {}
    };

}