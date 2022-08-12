#pragma once

#include "PoolObject.h"
#include <assert.h>
#include <iostream>
#include <list>
class EntityPool
{
    EntityPool(){}
    std::list<Entity*> entities;
    static EntityPool* instance;
public:
    
    static EntityPool* getInstance()
    {
        if (instance == 0)
        {
            instance = new EntityPool;
        }
        return instance;
    }

    Entity* create(Vector2f pos, Texture* tex, IntRect offset)
    {
        if (!entities.empty())
        {
            std::cout << "reusing";
            Entity* entity = entities.front();
            entity->setPosition(pos);
            entity->setTexture(tex);
            entity->setTextureRect(offset);
            entity->setActive(true);
            entities.pop_front();
            return entity;
        }
        else
        {
            std::cout << "new";
            Entity* ent = new Entity;
            ent->setPosition(pos);
            ent->setTexture(tex);
            ent->setTextureRect(offset);
            return ent;
        }
        
        /*if (entities.size() >= 20)
        {
            std::list<Entity*>::iterator it = entities.begin();
            std::list<Entity*>::iterator it1 = entities.end();
            advance(it, 20);

            entities.erase(it, it1);
        }*/
    }

    void returnObj(Entity* ent)
    {
        
        ent->reset();
        entities.push_back(ent);
    }
};