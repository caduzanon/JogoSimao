#pragma once
#include <Entity.hpp>
#include <Managers/SingleFrameAnimation.hpp>

namespace Entities{
    class StaticEntity : public Entity {
        private:
            Managers::SingleFrameAnimation sprite;
        public:
            StaticEntity();
            ~StaticEntity();
            void update (float dt) = 0;
            void initialize() = 0;
    };
}