#pragma once
#include <Entities/Entity.hpp>

namespace Game::Entities::Characters {
    class Player;
}

namespace Game::Entities::Obstacles{
    using namespace Characters;

    class Obstacle: public Entity {
        protected: 
            bool harmful;
        public:
            Obstacle(const Vector2f position, const Vector2f size, bool harms = false); //construtora
            virtual ~Obstacle();    //destrutora
            void saveDataBuffer();
            void update();
            void save();
            virtual void obstruct(Player* pPlayer) = 0; //virtual pura tem que ser implementada na filha

    };
}