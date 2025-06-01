#include <Managers/SingleFrameAnimation.hpp>
#include <Managers/Graphics.hpp>

namespace Managers{
    Graphics* SingleFrameAnimation::pGraphicsManager = Graphics::getInstance();
    
    SingleFrameAnimation::SingleFrameAnimation(const char* path, Math::CoordsF position, Math::CoordsF size, float scale) : texture(NULL), body(sf::Vector2f(size.x, size.y)){
        texture = pGraphicsManager->loadTexture(path);
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setScale(sf::Vector2f(scale, scale));
    }

    SingleFrameAnimation::~SingleFrameAnimation(){

    }

    void SingleFrameAnimation::update(Math::CoordsF position){

    }

    void SingleFrameAnimation::render(){
        pGraphicsManager->render(&body);
    }
}