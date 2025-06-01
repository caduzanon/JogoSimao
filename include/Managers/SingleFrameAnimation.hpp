#pragma once
#include <Math/CoordsTL.hpp>
#include <SFML/Graphics.hpp>

namespace Managers{
    class SingleFrameAnimation{
        private:
            sf::Texture* texture;
            sf::RectangleShape body;
        public:
            SingleFrameAnimation(const char* path, Math::CoordsF position, Math::CoordsF size);
            ~SingleFrameAnimation();
            void update(Math::CoordsF position);
            void render();
    };
}