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

} // namespace dusk
