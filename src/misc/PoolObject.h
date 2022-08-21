#pragma once

#include "Sprite2.h"
class Entity 
{
    const sf::Vector2f nullVector = sf::Vector2f(0, 0);
    sf::Texture nullTexture;
    static constexpr float speed = 200.0f;

    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Sprite sprite;
    bool active=false;

public:
    

    Entity() { active = true; }
    Sprite getSprite() { return sprite; }
    void setActive(bool act) { active = act; }
    void setTexture(sf::Texture* texture) { sprite.setTexture(*texture); }
    void setTextureRect(sf::IntRect intrect) { sprite.setTextureRect(intrect); }
    void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
    sf::Vector2f getPos() { return sprite.getPosition(); }

    void shoot(sf::Vector2f dir)
    {
        if (active)
            direction = dir;
        
    }

    void reset()
    {
        sprite.setPosition(nullVector);
        direction = nullVector;
        sprite.setTexture(nullTexture);
        active = false;
    }

    void update(float dt)
    {
        if (active)
            sprite.setPosition(sprite.getPosition() + direction * dt * speed);
        
        
    }

    void render(RenderTarget* target)
    {
        if(active)
            target->draw(sprite);
    }
};