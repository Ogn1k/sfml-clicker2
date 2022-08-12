#pragma once
#include "poolManager.h"
struct Player : sf::Drawable, sf::Transformable
{//sf::Vector2f pos
	/*Player(sf::Texture* texture)
		:
		//me(sf::Vector2f(20, 50)),
		bullet_sprite(*texture)
	{
		//me.setOrigin(10, 50);
		bullet_sprite.setOrigin(5, 5);
		//setPosition(pos);
	}

	void update(float dt)
	{
		for (size_t i{}; i < m_bullets.size();)
		{
			if (m_bullets[i]->life_time < 0 || action)
			{
				std::swap(m_bullets[i], m_bullets.back());
				EntityPool::instance().destroy(m_bullets.back());
				m_bullets.pop_back();
			}
			else
			{
				m_bullets[i]->update(dt);
				++i;
			}
		}
	}

	void doDelete(bool action)
	{
		this->action = action;
	}

	void shoot(sf::Vector2f target)
	{
		const auto pos = getPosition();
		target -= pos;
		target /= std::hypot(target.x, target.y);
		auto bull = EntityPool::instance().create(pos, target);
		if (bull) m_bullets.push_back(bull);
	}
	sf::Sprite bullet_sprite;
private:
	//sf::RectangleShape me;
	bool action;
	std::vector<Entity*> m_bullets;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		auto st = states;
		for (auto bull : m_bullets)
		{
			st.transform = states.transform;
			st.transform.translate(bull->m_pos);
			target.draw(bullet_sprite, st);
		}
		states.transform *= getTransform();
		//target.draw(me, states);
		//вспомнил
	}*/
};