#include <Managers/CollisionManager.hpp>

namespace Game::Managers{
    CollisionManager::CollisionManager(){
        ObstacleList = nullptr;
        CharactersList = nullptr;
        EnemiesList = nullptr;
        ProjectileList = nullptr;
    }

    CollisionManager::CollisionManager(Lists::EntityList* CharactersList, Lists::EntityList* ObstacleList, Lists::EntityList* EnemiesList, Lists::EntityList* ProjectileList) : 
    ObstacleList(ObstacleList), 
    CharactersList(CharactersList),
    EnemiesList(EnemiesList),
    ProjectileList(ProjectileList)
    {

    }

    void CollisionManager::setLists(Lists::EntityList* cList, Lists::EntityList* oList, Lists::EntityList* eList, Lists::EntityList* pList){
        if (CharactersList == nullptr)  { CharactersList = cList; }
        if (ObstacleList == nullptr)    { ObstacleList = oList; }
        if (EnemiesList == nullptr)     { EnemiesList = eList; }
        if (ProjectileList == nullptr)  { ProjectileList = pList; }
    }

    CollisionManager::~CollisionManager(){
        ObstacleList = nullptr;
        CharactersList = nullptr;
        //no other work to do. lists are not created by it.
    }

    const Vector2f CollisionManager::CalculateDistance(Entities::Entity* ent1, Entities::Entity* ent2) const{
        Vector2f distance (
            fabs((ent1->getPosition().x + ((ent1->getBody().getSize().x)/2.0f)) - (ent2->getPosition().x + ((ent2->getBody().getSize().x)/2.0f))),
            fabs((ent1->getPosition().y + ((ent1->getBody().getSize().y)/2.0f)) - (ent2->getPosition().y + ((ent2->getBody().getSize().y)/2.0f)))
        );
        Vector2f sumHalfRec(
            ((ent1->getBody().getSize().x)/2.0f + (ent2->getBody().getSize().x)/2.0f),
            ((ent1->getBody().getSize().y)/2.0f + (ent2->getBody().getSize().y)/2.0f)    
        );
        return Vector2f(distance.x - sumHalfRec.x, distance.y - sumHalfRec.y);
    }

    void CollisionManager::update(){

        //Players + Players
        for (int i=0; i < CharactersList->getSize() - 1; i++){
            Entities::Entity* aux1 = CharactersList->operator[](i);
            for(int j=i+1; j < CharactersList->getSize(); j++){
                Entities::Entity* aux2 = CharactersList->operator[](j);
                Vector2f dist = CalculateDistance(aux1, aux2);
                if (dist.x < 0.0f && dist.y < 0.0f){
                    aux1->collide(aux2, dist);
                }
            }
        }

        //Players & Obst.
        for (int i=0; i < CharactersList->getSize() - 1; i++){
            Entities::Entity* aux1 = CharactersList->operator[](i);
            for(int j=i+1; j < ObstacleList->getSize(); j++){
                Entities::Entity* aux2 = ObstacleList->operator[](j);
                Vector2f dist = CalculateDistance(aux1, aux2);
                if (dist.x < 0.0f && dist.y < 0.0f){
                    aux2->collide(aux1, dist);
                }
            }
        }

        //obstacles don't collide
    }
}