#include "ObjectCleaner.h"
#include "LoggingMacros.h"
#include <string>
#include <iostream>
#include "GameObject.h"

void ObjectCleaner::Cleaner(ObjectVector& list, sf::RenderWindow* window, Type type)const
{
#if SHOW_REMOVALS
	std::string log;
	switch (static_cast<int>(type))
	{
	case 0:log = "Player Bullet Scrubbed"; break;
	case 1:log = "AI Bullet Scrubbed"; break;
	case 2:log = "AI Scrubbed";
	}

	if (type == Type::kPlayerBullet)
	{
		const auto newEnd = std::remove_if
		(
			list.begin(), list.end(),
			[window, log](GameObject* tar)
			{
				if (tar->GetSprite().getPosition().y <= static_cast<float>(window->getSize().y) / window->getSize().y)
				{
					std::cout << log << "\n";
					delete tar;
					return true;
				}
				return false;
			}
		);
		list.erase(newEnd, list.end());
	}
	if (type != Type::kPlayerBullet)
	{
		const auto newEnd = std::remove_if
		(
			list.begin(), list.end(),
			[window, log](GameObject* tar)
			{
				if (tar->GetSprite().getPosition().y > static_cast<float>(window->getSize().y))
				{
					std::cout << log << "\n";
					delete tar;
					return true;
				}
				return false;
			}
		);
		list.erase(newEnd, list.end());
	}

#else

	if (type == Type::kPlayerBullet)
	{
		const auto newEnd = std::remove_if
		(
			list.begin(), list.end(),
			[window](GameObject* tar)
			{
				if (tar->GetSprite().getPosition().y <= static_cast<float>(window->getSize().y) / window->getSize().y)
				{
					
					delete tar;
					return true;
				}
				return false;
			}
		);
		list.erase(newEnd, list.end());
	}
	if (type != Type::kPlayerBullet)
	{
		const auto newEnd = std::remove_if
		(
			list.begin(), list.end(),
			[window](GameObject* tar)
			{
				if (tar->GetSprite().getPosition().y > static_cast<float>(window->getSize().y) + window->getSize().y)
				{
				
					delete tar;
					return true;
				}
				return false;
			}
		);
		list.erase(newEnd, list.end());
	}
#endif
}

void ObjectCleaner::MarkedObjectCleaner(ObjectVector& list, sf::RenderWindow* window, Type type)const
{
#if SHOW_MARKED_TARGET_REMOVAL
	const auto newEnd = std::remove_if
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
	list.erase(newEnd, list.end());
#else
	const auto newEnd = std::remove_if
	(
		list.begin(), list.end(),
		[window](GameObject* tar)
		{
			if (!tar->isAlive())
			{
				delete tar;
				return true;
			}
			return false;
		}
	);
	list.erase(newEnd, list.end());
#endif

}

void ObjectCleaner::Sweeper(Object* object, sf::RenderWindow& window, Type type)const
{
#if SHOW_TARGET_MOVED
	std::string log;
	switch (static_cast<int>(type))
	{
	case 0:log = "Player Bullet moved off screen"; break;
	case 1:log = "AI Bullet moved off screen"; break;
	case 2:log = "AI moved off screen";
	}
	std::cout << log << '\n';
#endif

    object->GetSprite().setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));


}

void ObjectCleaner::Sweeper(sf::Sprite* sprite, sf::RenderWindow& window, Type type)const
{
#if SHOW_TARGET_MOVED
	std::string log;
	switch (static_cast<int>(type))
	{
	case 0:log = "Player Bullet moved off screen"; break;
	case 1:log = "AI Bullet moved off screen"; break;
	case 2:log = "AI moved off screen";
	}
	std::cout << log << '\n';
#endif
    sprite->setPosition(0, static_cast<float>(window.getSize().y) * static_cast<float>(window.getSize().y));
	
}