#pragma once
#include <Entities/Being.hpp>
#include <SFML/System/Vector2.hpp>


//Skeleton of Entity - Abstract Class

namespace Game{
    namespace Entities{
        class Entity : public Being{
            protected:
                int x; //probably will swap to a vector of ints, easier that way.
                int y;
                //ostream buffer;
                void saveDataBuffer();
            public:
                Entity(int initial_x = 0, int initial_y = 0);
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;

                void setPosition(int new_x, int new_y);
                sf::Vector2i getPosition() const;
        };
    }
}