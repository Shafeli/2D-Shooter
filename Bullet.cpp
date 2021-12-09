#include "Bullet.h"

#include "Definition.h"

Bullet::Bullet(GameDataRef data,const sf::Vector2f& pos)
    :m_data(data)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Bullet Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition(pos);
}

void Bullet::Draw()
{
    m_data->window.draw(m_sprite);
}

void Bullet::Update(float dt)
{
    m_sprite.move(0, -gTargetYAxisDecreaseAmount);
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
