#pragma once
#include <Entities/Being.hpp>
<<<<<<< HEAD
#include <SFML/System/Vector2.hpp>

=======
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8

//Skeleton of Entity - Abstract Class

namespace Game{
    namespace Entities{
        class Entity : public Being{
            protected:
                int x; //probably will swap to a vector of ints, easier that way.
                int y;
<<<<<<< HEAD
                //ostream buffer;
                void saveDataBuffer();
            public:
                Entity(int initial_x = 0, int initial_y = 0);
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;

                void setPosition(int new_x, int new_y);
                sf::Vector2i getPosition() const;
=======
                RectangleShape body;
                //ostream buffer;
                void saveDataBuffer();
            public:
                Entity(const Vector2f position, const Vector2f size);
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;
                const RectangleShape getBody() const;
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
        };
    }
}