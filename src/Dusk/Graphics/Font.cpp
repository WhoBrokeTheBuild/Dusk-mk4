#include "Font.hpp"

namespace dusk
{

bool Font::Load(const string& filename)
{
    return m_SfFont.loadFromFile(filename);
}

sf::Font& Font::GetSfFont()
{
    return m_SfFont;
}

sf::Font Font::GetSfFont() const
{
    return m_SfFont;
}

} // namespace dusk
