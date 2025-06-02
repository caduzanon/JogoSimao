#pragma once
#include<Entities/Entity.hpp>

//Skeleton of Character - Abstract Entity Class

namespace Game{
    namespace Entities{
        namespace Characters{
            class Character : public Entity{
                protected:
                    int num_lives;
                public:
                    Character();
                    ~Character();
                    void saveDataBuffer();
                    virtual void update() = 0;  //not yet!
                    virtual void save() = 0;    //not yet!
                    virtual void move() = 0;    //each class will define its own
            };
        }
    }
}
