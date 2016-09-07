#include "Context.hpp"

namespace dusk
{

Context::Context(sf::RenderWindow* pWindow)
    : mp_Window(pWindow)
{
}

void Context::Clear()
{
    mp_Window->clear(sf::Color::Black);
}

void Context::Display()
{
    mp_Window->display();
}

} // namespace dusk
