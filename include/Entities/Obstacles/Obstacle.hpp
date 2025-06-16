#pragma once
#include <Entities/Entity.hpp>
#include <Entities/Characters/Character.hpp>
#include <SFML/Graphics.hpp>
#include <IDs.hpp>

namespace Game::Entities::Characters {
    class Player;
}

namespace Game::Entities::Obstacles{
    using namespace Characters;
    class Obstacle: public Entity {
        protected: 
            bool harmful;
        public:
            Obstacle(const Vector2f position, const Vector2f size, const Game::IDs id, bool harms = false);
            virtual ~Obstacle();    //destrutora
            void saveDataBuffer();
            virtual void update() = 0;
            virtual void save() = 0;
            virtual void obstruct(Vector2f ds, Characters::Character* pChar) = 0; //virtual pura tem que ser implementada na filha

    };
}