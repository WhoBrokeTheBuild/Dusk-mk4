#include "Text.hpp"

namespace dusk
{

Text::Text()
    : mp_Font(nullptr)
{
}

Text::Text(Font* pFont)
    : mp_Font(pFont)
{
}

uint Text::GetFontSize()
{
    return m_SfText.getCharacterSize();
}

void Text::SetFontSize(const uint& size)
{
    m_SfText.setCharacterSize(size);
}

} // namespace dusk
