#include <Managers/Animation.hpp>

namespace Managers{
    const float AnimationManager::Animation::switchTime = 0.2;
    Graphics* AnimationManager::pGraphicManager = Graphics::getInstance();
    AnimationManager::AnimationManager() : body(), animationMap(), currentID(Animation_ID::walk){
        body.setScale(sf::Vector2f(3,3));
    }

    AnimationManager::~AnimationManager(){
        std::map<Animation_ID, Animation*>::iterator it;
        for (it = animationMap.begin(); it != animationMap.end(); ++it)
            delete (it->second);
        animationMap.clear();
    }
    
    void AnimationManager::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount){
        Animation* anim = new Animation(path, imageCount);
        if (anim = NULL){
            std::cout << "Error: Could not create Animation in the addNewAnimation function!" << std::endl;
            exit(1);
        }
        animationMap.insert(std::pair<Animation_ID, Animation*>(id, anim));
        sf::IntRect rectSize = anim->getSize();

        body.setSize(sf::Vector2f(rectSize.width, rectSize.height));
        body.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);
    }

    void AnimationManager::update(Animation_ID id, bool facingLeft, Math::CoordsF position, float dt){
        if (currentID != id){
            currentID = id;
            animationMap[currentID]->reset();
        }
        animationMap[currentID]->update(dt, facingLeft);
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setTextureRect(animationMap[currentID]->getSize());
    }

    void AnimationManager::render(){
        pGraphicManager->render(&body);
    }
}