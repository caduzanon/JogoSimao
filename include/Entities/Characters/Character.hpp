#pragma once
#include<Entities/Entity.hpp>

//Character - Abstract Entity Class

namespace Game{
    namespace Entities{
        namespace Characters{
            class Character : public Entity{
                protected:
                    int num_lives;
                    Vector2f velocity;
                public:
                    Character(const Vector2f position, const Vector2f size, const Game::IDs id);
                    Character(const RectangleShape givenbody);
                    Character();
                    virtual ~Character();
                    void saveDataBuffer();
                    virtual void update() = 0;  //not defined yet: each class will define its own
                    virtual void save() = 0;    //not defined yet: each class will define its own
            };
        }
    }
}
