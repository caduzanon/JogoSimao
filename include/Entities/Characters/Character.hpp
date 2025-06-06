#pragma once
#include<Entities/Entity.hpp>

//Skeleton of Character - Abstract Entity Class

namespace Game{
    namespace Entities{
        namespace Characters{
            class Character : public Entity{
                protected:
                    int num_lives;
                    RectangleShape body;
                    Vector2f velocity;
                public:
                    Character();
                    ~Character();
                    void saveDataBuffer();
                    virtual void update() = 0;  //not defined yet: each class will define its own
                    virtual void save() = 0;    //not defined yet: each class will define its own
                    virtual void move() = 0;    //not defined yet: each class will define its own
                    const RectangleShape& getBody() const;
            };
        }
    }
}
