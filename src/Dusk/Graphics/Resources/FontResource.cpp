#include "FontResource.hpp"

namespace dusk
{

Resource* LoadFontResource(const string& filename)
{
    sf::Font font;
    font.loadFromFile(filename);

    FontResource* pResource = new FontResource(font);
    return (Resource*)pResource;
}

FontResource::FontResource(sf::Font font)
    : m_SfFont(font)
{
}

} // namespace dusk
