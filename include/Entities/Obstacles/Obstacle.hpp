#pragma once
#include <Entities/Entity.hpp>

namespace Game::Entities::Characters {
    class Player;
}

namespace Game::Entities::Obstacles{
    using namespace Characters;

    class Obstacle: public Entity {
        protected: 
            bool isdamage;
        public:
            Obstacle(const sf::Vector2f& position, const sf::Vector2f& size, bool damage = false); //construtora
            virtual ~Obstacle();    //destrutora
            void saveDataBuffer();
            void update();
            void save();
            virtual void obstaculize(Player* pPlayer) = 0; //virtual pura tem que ser implementada na filha

    };
}