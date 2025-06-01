#include <Unique.hpp>

Game::Unique::Unique() : pGM(GraphicsManager::getInstance()){
    update();
}

Game::Unique::~Unique(){

}

void Game::Unique::update(){
    RectangleShape player(Vector2f(20.0f, 20.0f));
    player.setFillColor(Color::Cyan);
    player.setPosition(Vector2f(300.0f, 300.0f));

    while(pGM->isWindowOpen()){
        Event evento;
        RenderWindow* window = pGM->getWindow();
        if(window->pollEvent(evento)){
            if(evento.type == Event::Closed || (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape)){
                pGM->closeWindow();
            }
        }
        pGM->clearWindow();
        pGM->render(&player);
        pGM->display();
    }
}