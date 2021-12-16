#include "CollisionDection.h"
#include "GameObject.h"

//Did Player Hit AI
////////////////////////////////////////////////////////
bool CollisionDection::DoesObjectOverlap(const ObjectVector& listOne, const ObjectVector& listTwo)
{
	//loops over sprites if two touch mark for death & sends to cleaner
	for (const auto& i : listOne)
	{
		for (const auto& j : listTwo)
		{
			if (i->GetSprite().getGlobalBounds().intersects(j->GetSprite().getGlobalBounds()))
			{
				i->MarkedForDeath();
				j->MarkedForDeath();
				return true;
			}
		}
	}
	return false;
}


//Did AI Hit Player
////////////////////////////////////////////////////////
bool CollisionDection::IsPlayerHitDetection(const ObjectVector& list, Object* object, Clock& timer)
{
	//if player is not hit return false
	//if player spawn timer is not over 1.5s return false
	//if player is hit and timer is greater then retrun true
	for (auto& i : list)
	{
		if (i->GetSprite().getGlobalBounds().intersects(object->GetSprite().getGlobalBounds()))
		{
			if (timer.getElapsedTime().asSeconds() < 1.5f)
			{
				i->MarkedForDeath();
				return false;
			}
			i->MarkedForDeath();
			timer.restart();
			object->MakeSound();
			return true;
		}
	}
	return false;
}

bool CollisionDection::DoesObjectTouchWindowLeft(Object* object)
{
	if (object->GetSprite().getGlobalBounds().left <= 0.f)
	{
		return true;
	}
	return false;
}

bool CollisionDection::DoesObjectTouchWindowRight(Object* object, const sf::RenderWindow* window)
{
	if (object->GetSprite().getGlobalBounds().left + object->GetSprite().getGlobalBounds().width >= window->getSize().x)
	{
		return true;
	}
	return false;
}

bool CollisionDection::DoesObjectTouchWindowTop(Object* object, const sf::RenderWindow* window)
{
	if (object->GetSprite().getPosition().y <= static_cast<float>(window->getSize().y) / window->getSize().y)
	{
		return true;
	}
	return false;
}

bool CollisionDection::DoesObjectTouchWindowBottom(Object* object, const sf::RenderWindow* window)
{
	if (object->GetSprite().getPosition().y > static_cast<float>(window->getSize().y))
	{
		return true;
	}
	return false;
}



