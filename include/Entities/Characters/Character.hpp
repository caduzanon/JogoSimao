#pragma once
#include<Entities/Entity.hpp>

//Skeleton of Character - Abstract Entity Class

namespace Game{
    namespace Entities{
        namespace Characters{
            class Character : public Entity{
                protected:
                    int num_lives;
<<<<<<< HEAD
=======
                    RectangleShape body;
                    Vector2f velocity;
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
                public:
                    Character();
                    ~Character();
                    void saveDataBuffer();
<<<<<<< HEAD
                    virtual void update() = 0;  //not yet!
                    virtual void save() = 0;    //not yet!
                    virtual void move() = 0;    //each class will define its own
=======
                    virtual void update() = 0;  //not defined yet: each class will define its own
                    virtual void save() = 0;    //not defined yet: each class will define its own
                    virtual void move() = 0;    //not defined yet: each class will define its own
                    const RectangleShape& getBody() const;
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
            };
        }
    }
}
