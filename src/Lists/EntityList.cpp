#include <Lists/EntityList.hpp>

namespace Game{
    namespace Lists{
        EntityList::EntityList() : EntitiesListObject() {
        }

        EntityList::~EntityList(){
            EntitiesListObject.clearList();
        }

        void EntityList::addEntity(Entity* entity){
            EntitiesListObject.addElement(entity);
        }

        void EntityList::addEntity(Entity* entity, int position){
            EntitiesListObject.addElement(entity, position);
        }

        void EntityList::removeEntity(Entity* entity, const bool deletion){
            EntitiesListObject.removeElement(entity, deletion);
        }

        void EntityList::removeEntity(int position, const bool deletion){
            EntitiesListObject.removeElement(position, deletion);
        }

        int EntityList::getSize(){
            return EntitiesListObject.getSize();
        }

        Entity* EntityList::operator[](int position){
            return EntitiesListObject.operator[](position);
        }

        void EntityList::update(){ //usando gerenciador gráfico!
            int size = EntitiesListObject.getSize();
            Entity* aux = nullptr;
            for (int i = 0; i< size; i++){
                aux = EntitiesListObject.operator[](i);
                aux->update();
                aux->render();
            }
        }

        void EntityList::RenderEntities(){
            int size = EntitiesListObject.getSize();
            Entity* aux = nullptr;
            for (int i = 0; i< size; i++){
                aux = EntitiesListObject.operator[](i);
                aux->render();
            }
        }
    }
}