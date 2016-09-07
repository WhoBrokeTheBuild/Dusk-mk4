#ifndef DUSK_WINDOW_HPP
#define DUSK_WINDOW_HPP

#include <Dusk/Types.hpp>
#include <Dusk/Vector2.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

class RenderContext;

class Window
{
public:
    enum class Style : unsigned int
    {
        None = 0,
        Titlebar = 1 << 0,
        Resize = 1 << 1,
        Close = 1 << 2,
        Fullscreen = 1 << 3,
        Default = Titlebar | Resize | Close
    };

    Window() = delete;
    Window(const Window&) = delete;

    Window(const uint& width, const uint& height, const string& title, const Style& style = Style::Default);
    ~Window() = default;

    void Update();

    void Show();
    void Hide();
    void SetVisible(const bool& visible);

    void SetSize(const Vector2u& size);
    void SetSize(const uint& width, const uint& height);

    void SetTitle(const string& title);

    bool IsOpen();
    void Close();

    RenderContext* GetRenderContext();

private:
    unique_ptr<sf::RenderWindow> mp_SfWindow;

    unique_ptr<RenderContext> mp_RenderContext;

}; // class Window

} // namespace dusk

#endif // DUSK_WINDOW_HPP
