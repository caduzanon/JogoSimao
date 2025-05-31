#pragma once

#include <Entities/Characters/Player.hpp>
#include <Managers/Graphics.hpp>

class Game {
    private:
        Entities::Characters::Player Player1;
        Managers::Graphics pGraphicManager;
    public:
        Game();
        ~Game();
        void execute();
};