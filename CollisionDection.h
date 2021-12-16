#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
class GameObject;

class CollisionDection
{
	using Object = GameObject;
	using ObjectVector = std::vector<GameObject*>;
	using Clock = sf::Clock;
public:

	//Did Player Hit AI
	////////////////////////////////////////////////////////
	bool DoesObjectOverlap(const ObjectVector& listOne, const ObjectVector& listTwo);

	//Did AI Hit Player
	////////////////////////////////////////////////////////
	bool IsPlayerHitDetection(const ObjectVector& list, Object* object, Clock& timer);

	//Window Collision
    ////////////////////////////////////////////////////////
	bool DoesObjectTouchWindowLeft(Object* object);
	bool DoesObjectTouchWindowRight(Object* object, const sf::RenderWindow* window);
	bool DoesObjectTouchWindowTop(Object* object, const sf::RenderWindow* window);
	bool DoesObjectTouchWindowBottom(Object* object, const sf::RenderWindow* window);

};
