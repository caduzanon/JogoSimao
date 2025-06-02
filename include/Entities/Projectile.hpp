#pragma once
#include <Entities/Entity.hpp>

//Skeleton of Projectile

namespace Game{
    namespace Entities{
        class Projectile : public Entity{ //inherits Entity
            protected:
                bool active;
            public:
                Projectile();
                ~Projectile();
                void update();  //as required by Entity
                void save();    //as required by Entity
        };
    }
}
