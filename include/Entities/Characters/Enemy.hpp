#include <Character.hpp>
#include <Player.hpp>

namespace Game::Entities::Characters{
    class Enemy : public Character{
        protected:
            int evilness_level;
        public:
            Enemy();
            ~Enemy();
            void saveDataBuffer();
            virtual void update() = 0;
            virtual void damage(Player* pPlayer) = 0;
            virtual void save() = 0;
    };
}