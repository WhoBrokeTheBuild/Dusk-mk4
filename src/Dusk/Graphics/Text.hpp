#ifndef DUSK_TEXT_HPP
#define DUSK_TEXT_HPP

#include <Dusk/Graphics/Drawable.hpp>
#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

class Text : public Drawable
{
public:
    Text(const Text&) = delete;

    Text();
    Text(Font* pFont);

    void SetFont(Font* pFont);
    Font* GetFont();

    uint GetFontSize() const;
    void SetFontSize(const uint& size);

protected:
    Font* mp_Font;

    sf::Text m_SfText;

}; // class Text

} // namespace dusk

#endif // DUSK_TEXT_HPP
