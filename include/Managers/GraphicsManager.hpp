#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Managers{
    class GraphicsManager{
        private:
            RenderWindow* window;
            //Singleton
            static GraphicsManager* instance;
            GraphicsManager();
        public:
            ~GraphicsManager();
            static GraphicsManager* getInstance();
            RenderWindow* getWindow();
            void render(RectangleShape* body);
            void display();
            void clearWindow();
            bool isWindowOpen() const;
            void closeWindow();
    };
}
