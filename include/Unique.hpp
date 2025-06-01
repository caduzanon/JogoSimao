#pragma once
#include <Managers/GraphicsManager.hpp>
#include <iostream>

using namespace Managers;

namespace Game{
    class Unique{
        private:
            GraphicsManager* pGM;
        public:
            Unique();
            ~Unique();
            void update();
    };
}