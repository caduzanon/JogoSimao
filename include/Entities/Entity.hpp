#pragma once
#include <Math/CoordsTL.hpp>

namespace Entities{
    enum ID {
        empty = 0,
        player,
        platform, 
        projectile,
        obstacle
    };
    class Entity{
        private:
            Math::CoordsF position;
            Math::CoordsF size;
            ID id;
        public:
            Entity(Math::CoordsF position = Math::CoordsF(0.0f, 0.0f), Math::CoordsF size = Math::CoordsF(0.0f, 0.0f), ID id = empty); //construtora inicializando tudo com zero
            ~Entity();
            void setPosition(Math::CoordsF position);
            void setSize(Math::CoordsF size);
            Math::CoordsF getPosition() const;
            Math::CoordsF getSize() const;
            ID getID() const;
            virtual void render();
            virtual void update(float dt) = 0;
            virtual void initialize() = 0;
    };
}