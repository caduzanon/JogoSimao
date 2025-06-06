#pragma once
#include <Entities/Being.hpp>

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
                Entity(const Vector2f position, const Vector2f size);
                Entity(const RectangleShape givenbody);
                Entity();
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;
                void setPosition(int new_x, int new_y);
                sf::Vector2i getPosition() const;
        };
    }
}