#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

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

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

bool InputManager::APressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return true;
	}
	return false;
}

bool InputManager::DPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return true;
	}
	return false;
}

bool InputManager::SpacePressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		return true;
	}
	return false;
}

