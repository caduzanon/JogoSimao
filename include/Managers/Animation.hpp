#pragma once
#include <Math/CoordsTL.hpp>
#include <Managers/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <map>

namespace Managers{
    enum Animation_ID{
        walk = 0,
        idle = 1,
        attack = 2
    };
    class AnimationManager {
        private:
            class Animation {
                private:
                    const unsigned int imageCount;
                    unsigned int currentImage;
                    sf::Texture* texture;
                    float totalTime;
                    sf::IntRect rectSize;
                    static const float switchTime;
                public:
                    Animation (const char* path, const unsigned int imageCount) : imageCount(imageCount), currentImage(0), texture(pGraphicManager->loadTexture(path)), totalTime(0.0f), rectSize() {
                        if (texture == NULL) {
                            std::cout << "Error when loading Animation texture on Animation constructor." << std::endl;
                            exit(1);
                        }
                        rectSize.width = texture->getSize().x / float(imageCount);
                        rectSize.height = texture->getSize().y;
                    }
                    ~Animation() { }

                    void update(float dt, bool facingLeft){
                        totalTime += dt;
                        if (totalTime >= switchTime){
                            totalTime -= switchTime;
                            currentImage++;
                            if (currentImage >= imageCount)
                                currentImage = 0; //loop back to first
                        }
                        if (facingLeft){
                            rectSize.left = (currentImage+1)*abs(rectSize.width);
                            rectSize.width = -abs(rectSize.width);
                        }
                        else{
                            rectSize.left = currentImage * rectSize.width;
                            rectSize.width = abs(rectSize.width);
                        }
                    }

                    void reset(){
                        currentImage = 0;
                        totalTime = 0;
                    }

                    sf::IntRect getSize() const { return rectSize; }
                    sf::Texture* getTexture() const{ return texture; }
            }; //end Animation
        private:
            sf::RectangleShape body;
            std::map<Animation_ID, Animation*> animationMap;
            Animation_ID currentID;
            static Managers::Graphics* pGraphicManager;
        public:
            AnimationManager();
            ~AnimationManager();

            void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount);
            void update(Animation_ID id, bool facingLeft, Math::CoordsF position, float dt);
            void render();
    };//class AnimationManager
} //namespace Managers