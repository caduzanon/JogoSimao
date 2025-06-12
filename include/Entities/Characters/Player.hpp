#pragma once
#include <iostream>
#include <Entities/Characters/Character.hpp>
#include <IDs.hpp>
#include <Observer/Observer.hpp> 
/**
 * @brief Essa classe é essencial
 */
namespace Game{
    namespace Entities{
        namespace Characters{
            class Player : public Character, public Observer::Observer{
                private:
                    int player_id;
                protected:
                    int points;
                    bool isPlayer1;
                    float movementSpeed; //define a velocidade de movimento do jogador, mudar para implementar com conceito de fisica
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1, const IDs id = IDs::Player1);
                    Player(const RectangleShape givenbody);
                    Player();
                    ~Player();

                    void render(sf::RenderTarget& target) override;
                    void update() override;
                    void save() override;

                    void move();
                    void notifyKeyPressed(sf::Keyboard::Key key) override;
                    void notifyKeyReleased(sf::Keyboard::Key key) override;
            };
        }
    }
}

