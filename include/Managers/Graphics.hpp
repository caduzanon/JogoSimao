#pragma once

#include <Math/CoordsTL.hpp>
#include <SFML/Graphics.hpp>

#include <map>

namespace Managers {
    class Graphics{
        private:
            sf::RenderWindow* window;
            sf::View view;
            std::map<const char*, sf::Texture*> textureMap;
            sf::Font* font;
            sf::Clock clock;
            static float dt;
        public:
            Graphics();
            ~Graphics();
            void render(sf::RectangleShape* body);
            void render(sf::Text* text);
            void display();
            void clear();
            sf::RenderWindow* getWindow() const;
            bool isWindowOpen() const;
            void closeWindow();
            void handleWindowResize();
            sf::Vector2u getWindowSize() const;
            void centerView(Math::CoordsF position);
            sf::Texture* loadTexture(const char* path);
            sf::Font* getFont();
            void updateDeltaTime();
    };
}