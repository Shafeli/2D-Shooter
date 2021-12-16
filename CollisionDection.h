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
	bool IsPlayerHitDetection(ObjectVector& list, Object* object, Clock& timer);

};
