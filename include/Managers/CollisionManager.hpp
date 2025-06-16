#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Lists/EntityList.hpp>
#include <cmath>

namespace Game{
    namespace Managers{
        class CollisionManager{
            private:
                Lists::EntityList* CharactersList;
                Lists::EntityList* ObstacleList;
                Lists::EntityList* EnemiesList;
                Lists::EntityList* ProjectileList;
            public:
                CollisionManager();
                CollisionManager(Lists::EntityList* CharactersList, Lists::EntityList* ObstacleList, Lists::EntityList* EnemiesList, Lists::EntityList* ProjectileList);
                ~CollisionManager();
                void setLists(Lists::EntityList* cList, Lists::EntityList* oList, Lists::EntityList* eList, Lists::EntityList* pList);
                const Vector2f CalculateDistance(Entities::Entity* ent1, Entities::Entity* ent2) const;
                void update();
        };
    }
}