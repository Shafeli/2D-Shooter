#include "Target.h"

Target::Target(GameDataRef data)
    :m_data(data)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Target Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition((m_data->window.getSize().x / 2 ) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
}

void Target::Draw()
{
    m_data->window.draw(m_sprite);
}

void Target::Update(float dt)
{

}
