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
            /*Singleton Standard*/
            static Managers::Graphics* instance;
            Graphics();
        public:
            ~Graphics();
            static Graphics* getInstance();
            void render(sf::RectangleShape* body);
            void render(sf::Text* text);
            void display();
            void clear();
            bool isWindowOpen() const;
            void closeWindow();
            void handleWindowResize();
            sf::Vector2u getWindowSize() const;
            void centerView(Math::CoordsF position);
            sf::Texture* loadTexture(const char* path);
            sf::Font* getFont();
            float updateDeltaTime();
    };
}