#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

// is button clicked
bool InputManager::IsSpriteClicked(sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (playButtonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}

	return false;
}

//uses SFML to get mouse pos
sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

//SFML KEY Binding
bool InputManager::APressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return true;
	}
	return false;
}

//SFML KEY Binding
bool InputManager::DPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return true;
	}
	return false;
}

//SFML KEY Binding
bool InputManager::SpacePressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		return true;
	}
	return false;
}

