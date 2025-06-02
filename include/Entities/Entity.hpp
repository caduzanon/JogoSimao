#pragma once
#include <Entities/Being.hpp>

//Skeleton of Entity - Abstract Class

namespace Game{
    namespace Entities{
        class Entity : public Being{
            protected:
                int x;
                int y;
                ostream buffer;
                void saveDataBuffer();
            public:
                Entity();
                virtual ~Entity();
                virtual void update() = 0;
                virtual void save() = 0;
        };
    }
}