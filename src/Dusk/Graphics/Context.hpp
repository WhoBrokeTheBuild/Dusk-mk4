#ifndef DUSK_CONTEXT_HPP
#define DUSK_CONTEXT_HPP

#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

/// The context used to render things to
/** The context that contains methods for drawing primitives and clearing the screen.
 */
class Context
{
    friend class Window;

public:
    Context() = delete;
    Context(const Context&) = delete;
    virtual ~Context() = default;

    void Clear();
    void Display();

private:
    Context(sf::RenderWindow* pWindow);

    sf::RenderWindow* mp_Window;

}; // class Context

} // namespace dusk

#endif // DUSK_CONTEXT_HPP
