#include "Player.h"

#include <iostream>

#include "Bullet.h"

Player::Player(GameDataRef data)
    :m_data(data)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Player Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition((m_data->window.getSize().x / 2) - (m_sprite.getGlobalBounds().width / 2),
        m_data->window.getSize().y - m_sprite.getGlobalBounds().height);

    m_sprite.getPosition();
}

void Player::Draw()
{
    m_data->window.draw(m_sprite);
  
}

void Player::Update(float dt)
{
    // Check left side of the window
    if (m_sprite.getGlobalBounds().left <= 0.f)
        m_sprite.move(m_sprite.getGlobalBounds().width / 9 ,0.f);

    //check right side of the window 
    if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_sprite.move(-m_movementSpeed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_sprite.move(+m_movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (m_rateOfFire.getElapsedTime().asSeconds() > gRateOfFire)
        {
            //std::cout << "Bang!\n";
            m_fireShot = true;
            m_rateOfFire.restart();
        }
    }
 
}

bool Player::FireShot()
{
    bool isShot = false;

    if(m_fireShot)
    {
        isShot = true;
    }

    m_fireShot = false;

    return isShot;
}

const sf::Vector2f& Player::GetPOS()
{
    // TODO: insert return statement here
    return m_sprite.getPosition();
}
