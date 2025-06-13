#include <Character.hpp>
#include <Enemy.hpp>
#include <Player.hpp>

namespace Game::Entities::Characters{
    class Dragon : public Enemy{
        protected:
            short int strength;
        public:
            Dragon();
            ~Dragon();
            void damage(Player* pPlayer);
            void update();
            void save();
    };
}