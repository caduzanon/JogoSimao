#include <Managers/SingleFrameAnimation.hpp>
#include <Managers/Graphics.hpp>

namespace Managers{
    SingleFrameAnimation::SingleFrameAnimation(const char* path, Math::CoordsF position, Math::CoordsF size){
        texture = Graphics::getInstance()->loadTexture(path);
    }
}