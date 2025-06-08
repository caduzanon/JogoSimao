#pragma once
#include <Entities/Being.hpp>

//Skeleton of Entity - Abstract Class

namespace Game{
    namespace Entities{
        class Entity : public Being{
            protected:
                int x; //should we swap?
                int y;
                //ostream buffer;
                bool alive;
                void saveDataBuffer();
            public:
                Entity(const Vector2f position, const Vector2f size);
                Entity(const RectangleShape givenbody);
                Entity();
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;
                virtual void render(RenderTarget& target) = 0;
                void setPosition(int new_x, int new_y);
                Vector2i getPosition() const;
        };
    }
}