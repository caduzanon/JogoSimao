#pragma once
#include <iostream>
#include <Entities/Characters/Character.hpp>

<<<<<<< HEAD
/**
 * @brief Essa classe é essencial
 */
=======
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
namespace Game{
    namespace Entities{
        namespace Characters{
            class Player : public Character{
                private:
                    int points;
                    bool isPlayer1;
<<<<<<< HEAD
                    RectangleShape body;
                    Vector2f velocity;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1);
                    Player(const RectangleShape body);
                    Player();
                    ~Player();
                    const RectangleShape& getBody() const; //const tava me pegando
=======
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1);
                    Player(const RectangleShape givenbody);
                    Player();
                    ~Player();
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
                    void update();
                    void move();
                    void save();
            };
        }
    }
}

