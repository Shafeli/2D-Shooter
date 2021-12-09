#include "Bullet.h"

#include "Definition.h"

Bullet::Bullet(GameDataRef data,const sf::Vector2f& pos, float Direction)
    :m_data(data)
    ,m_direction(Direction)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Bullet Sprite"));
    m_fireSound.setBuffer(m_data->assets.GetSound("Lazer Sound"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition(pos);

}

void Bullet::Draw()
{
    m_data->window.draw(m_sprite);
}

void Bullet::Lazer()
{
    m_fireSound.play();
}

void Bullet::Update(float dt)
{
    m_sprite.move(0, m_direction);
}

const sf::Vector2f& Bullet::GetPOS()
{
    // TODO: insert return statement here
    return m_sprite.getPosition();
}

const sf::Sprite& Bullet::GetSprite()
{
    // TODO: insert return statement here
    return m_sprite;
}
