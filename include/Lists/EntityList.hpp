#pragma once
#include <Lists/ListTL.hpp>
#include <Entities/Entity.hpp>

namespace Game{
    namespace Lists{
        using namespace Entities;
        class EntityList{
            private:
                List<Entity> EntitiesListObject;
            public:
                EntityList();
                ~EntityList();
                void addEntity(Entity* entity);
                void addEntity(Entity* entity, int position);
                void removeEntity(Entity* entity, const bool deletion);
                void removeEntity(int position, const bool deletion);
                int getSize();
                Entity* operator[](int position);
                void update();
                //void RenderEntities();
                void RenderEntities(sf::RenderTarget& target);
        };
    }
}