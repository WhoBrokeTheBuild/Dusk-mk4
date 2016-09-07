#include "RenderContext.hpp"

namespace dusk
{

RenderContext::RenderContext(sf::RenderWindow* pWindow)
    : mp_Window(pWindow)
{
}

void RenderContext::Clear()
{
    mp_Window->clear(sf::Color::Black);
}

void RenderContext::Display()
{
    mp_Window->display();
}

void RenderContext::Draw(Texture* pTexture, Vector2f position)
{
    sf::Sprite tmp(pTexture->GetSfTexture());
    tmp.setPosition(position);
    mp_Window->draw(tmp);
}

} // namespace dusk
