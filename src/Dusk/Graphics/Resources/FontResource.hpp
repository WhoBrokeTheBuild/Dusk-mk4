#ifndef DUSK_FONT_RESOURCE_HPP
#define DUSK_FONT_RESOURCE_HPP

#include <Dusk/Resources/Resource.hpp>
#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

Resource* LoadFontResource(const string& filename);

class FontResource : public Resource
{

    friend Resource* LoadFontResource(const string& filename);

public:
    FontResource() = delete;
    FontResource(const FontResource&) = delete;
    virtual ~FontResource() = default;

protected:
    FontResource(sf::Font font);

    sf::Font m_SfFont;

}; // class FontResource

} // namespace dusk

#endif // DUSK_FONT_RESOURCE_HPP
