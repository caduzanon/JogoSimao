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
        EnemiesList = nullptr;
        ProjectileList = nullptr;
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

        //Players + Enemies
        if (CharactersList != nullptr){
            if(EnemiesList != nullptr){
                //std::cout << "Checking enemy collisions!" << std::endl;
                for (int i=0; i < CharactersList->getSize(); i++){
                    Entities::Entity* aux1 = CharactersList->operator[](i);
                    for(int j=0; j < EnemiesList->getSize(); j++){
                        Entities::Entity* aux2 = EnemiesList->operator[](j);
                        Vector2f dist = CalculateDistance(aux1, aux2);
                        if (dist.x < 0.0f && dist.y < 0.0f){
                            aux1->collide(aux2, dist); //here, aux1 is player, aux2 is enemy. Player function is called!
                        }
                    }
                }
            }
            if (ObstacleList != nullptr){
                //std::cout << "Checking obstacle collisions!" << std::endl;
                //Players & Obst.
                for (int i=0; i < CharactersList->getSize(); i++){
                    Entities::Entity* aux1 = CharactersList->operator[](i);
                    for(int j=0; j < ObstacleList->getSize(); j++){
                        Entities::Entity* aux2 = ObstacleList->operator[](j);
                        Vector2f dist = CalculateDistance(aux1, aux2);
                        //std::cout << "Distance:" << dist.x << "," << dist.y << std::endl;
                        if (dist.x < 0.0f && dist.y < 0.0f){
                            aux2->collide(aux1, dist); //here, aux2 is obst, aux1 is player. obstacle function is called!
                        }
                    }
                }
            }
            if (ProjectileList != nullptr){
                //Players & Proj.
                //std::cout << "Checking projectile collisions!" << std::endl;
                for (int i=0; i < CharactersList->getSize(); i++){
                    Entities::Entity* aux1 = CharactersList->operator[](i);
                    for(int j=0; j < ProjectileList->getSize(); j++){
                        Entities::Entity* aux2 = ProjectileList->operator[](j);
                        Vector2f dist = CalculateDistance(aux1, aux2);
                        if (dist.x < 0.0f && dist.y < 0.0f){
                            aux2->collide(aux1, dist); //here, aux2 is projectile, aux1 is player. projectile function is called!
                        }
                    }
                }
            }
        }
        else{
            std::cout << "Collision Manager called with empty CharacterList" << std::endl;
        }
        //obstacles don't collide
    }
}