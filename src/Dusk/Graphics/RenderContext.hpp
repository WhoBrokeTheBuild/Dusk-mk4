#ifndef DUSK_RENDER_CONTEXT_HPP
#define DUSK_RENDER_CONTEXT_HPP

#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

/// The object used to draw to the screen buffer
/** The context that contains methods for drawing primitives and clearing the screen.
 */
class RenderContext
{
    friend class Window;

public:
    RenderContext() = delete;
    RenderContext(const RenderContext&) = delete;
    virtual ~RenderContext() = default;

    void Clear();
    void Display();

private:
    RenderContext(sf::RenderWindow* pWindow);

    sf::RenderWindow* mp_Window;

}; // class RenderContext

} // namespace dusk

#endif // DUSK_RENDER_CONTEXT_HPP
