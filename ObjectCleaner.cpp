#include "ObjectCleaner.h"

#include <cassert>

#include "GameObject.h"
#include <iostream>



void ObjectCleaner::Cleaner(ObjectVector& list, sf::RenderWindow* window, Type type)const
{
	switch (static_cast<int>(type))
	{
	case 0:
		for (auto& i : list)
		{
			const auto NewEnd = std::remove_if
			(
				list.begin(), list.end(),
				[window](GameObject* tar)
				{
					if (tar->GetSprite().getPosition().y <= static_cast<float>(window->getSize().y) / window->getSize().y)
					{
						std::cout << "Player Bullet Scrubbed \n";
						delete tar;
						return true;
					}
					return false;
				}
			);
			list.erase(NewEnd, list.end());
		}
		break;
	case 1:
		for (auto& i : list)
		{
			const auto NewEnd = std::remove_if
			(
				list.begin(), list.end(),
				[window](GameObject* tar)
				{
					if (tar->GetSprite().getPosition().y > static_cast<float>(window->getSize().y))
					{
						std::cout << "AI Bullet Scrubbed \n";
						delete tar;
						return true;
					}
					return false;
				}
			);
			list.erase(NewEnd, list.end());
		}
		break;
	case 2:
		for (auto& i : list)
		{
			const auto NewEnd = std::remove_if
			(
				list.begin(), list.end(),
				[window](GameObject* tar)
				{
					if (tar->GetSprite().getPosition().y > static_cast<float>(window->getSize().y))
					{
						std::cout << "AI Scrubbed \n";
						delete tar;
						return true;
					}
					return false;
				}
			);
			list.erase(NewEnd, list.end());
		}
	}
}

void ObjectCleaner::MarkedObjectCleaner(ObjectVector& list, sf::RenderWindow* window, Type type)const
{
	assert(type != Type::kEnemyBullet);
	for (auto& i : list)
	{
		const auto NewEnd = std::remove_if
		(
			list.begin(), list.end(),
			[window](GameObject* tar)
			{
				if (!tar->isAlive())
				{
					std::cout << "Marked Object Scrubbed \n";
					delete tar;
					return true;
				}
				return false;
			}
		);
		list.erase(NewEnd, list.end());
	}

}

void ObjectCleaner::Sweeper(Object* object, sf::RenderWindow& window, Type type)const
{

	switch(static_cast<int>(type))
	{
	case 0:
		std::cout << "Player Bullet moved off screen \n";
		object->GetSprite().setPosition(0, static_cast<float>(window.getSize().y) / static_cast<float>(window.getSize().y));
		break;
	case 1:
		std::cout << "AI Bullet moved off screen \n";
		object->GetSprite().setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));
		break;
	case 2:
		std::cout << "Failed AI moved off screen \n";
		object->GetSprite().setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));
	}

}

void ObjectCleaner::Sweeper(sf::Sprite* sprite, sf::RenderWindow& window, Type type)const
{
	switch (static_cast<int>(type))
	{
	case 0:
		std::cout << "Player Bullet moved off screen \n";
		sprite->setPosition(0, static_cast<float>(window.getSize().y) / static_cast<float>(window.getSize().y));
		break;
	case 1:
		std::cout << "AI Bullet moved off screen \n";
		sprite->setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));
		break;
	case 2:
		std::cout << "Failed AI moved off screen \n";
		sprite->setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));
	}
}