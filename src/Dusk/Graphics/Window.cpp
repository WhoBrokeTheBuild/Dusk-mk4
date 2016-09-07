#include "Window.hpp"

#include <Dusk/Graphics/Context.hpp>

namespace dusk
{

Window::Window(const uint& width, const uint& height, const string& title, const Style& style /*= Style::Default*/)
    : mp_SfWindow(new sf::RenderWindow(sf::VideoMode(width, height), title, (sf::Uint32)style))
    , mp_Context(new Context(mp_SfWindow.get()))
{
}

void Window::Update()
{
    sf::Event evt;
    while (mp_SfWindow->pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
        {
            mp_SfWindow->close();
        }
    }
}

void Window::Show()
{
    mp_SfWindow->setVisible(true);
}

void Window::Hide()
{
    mp_SfWindow->setVisible(false);
}

void Window::SetVisible(const bool& visible)
{
    mp_SfWindow->setVisible(visible);
}

void Window::SetSize(const Vector2u& size)
{
    mp_SfWindow->setSize(size);
}

void Window::SetSize(const uint& width, const uint& height)
{
    mp_SfWindow->setSize(Vector2u(width, height));
}

void Window::SetTitle(const string& title)
{
    mp_SfWindow->setTitle(title);
}

bool Window::IsOpen()
{
    return mp_SfWindow->isOpen();
}

void Window::Close()
{
    mp_SfWindow->close();
}

Context* Window::GetContext()
{
    return mp_Context.get();
}

} // namespace dusk
