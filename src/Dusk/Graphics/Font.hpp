#ifndef DUSK_FONT_HPP
#define DUSK_FONT_HPP

#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

class Font
{

    friend class RenderContext;

public:
    Font() = default;
    Font(const Font&) = delete;
    virtual ~Font() = default;

    bool Load(const string& filename);

protected:
    sf::Font& GetSfFont();
    sf::Font GetSfFont() const;

    sf::Font m_SfFont;

}; // class Font

} // namespace dusk

#endif // DUSK_FONT_HPP
