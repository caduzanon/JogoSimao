#include "graphics.h"

int main(){

    Graphics gGraphics(1920, 1080, "teste");

    windowHandle gWindowHandle = gGraphics.getWindowHandle();
    
    spriteID testSprite = gGraphics.createSprite(gGraphics.loadTexture("../assets/green_alien.png"));//loadTexture retorna o ID da textura direto para createSprite
    
    spriteRect testRect(0, 0, 16, 20);
    gGraphics.setSpriteRect(testSprite, testRect);
    
    gGraphics.setSpritePos(testSprite,40.0,10.0);
    gGraphics.setBackground(testSprite);

    sf::Event testEvent; //a ideia é nao usar tipos da sfml nesse arquivo, mas é so pra testar
    while(gGraphics.isWindowOpen()){
        while (gWindowHandle->pollEvent(testEvent))//trata dos eventos, melhor criar uma classe pra isso depois
        {
            if (testEvent.type == sf::Event::Closed){
                gGraphics.closeWindow();
            }
        }

        //gGraphics.drawSprite(testSprite);
        gGraphics.render();
    }
    getchar();
    return 0;
}