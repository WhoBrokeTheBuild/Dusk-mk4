#ifndef DUSK_TEXTURE_RESOURCE_HPP
#define DUSK_TEXTURE_RESOURCE_HPP

#include <Dusk/Resources/Resource.hpp>
#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

Resource* LoadTextureResource(const string& filename);

class TextureResource : public Resource
{

    friend Resource* LoadTextureResource(const string& filename);

public:
    TextureResource() = delete;
    TextureResource(const TextureResource&) = delete;
    virtual ~TextureResource() = default;

protected:
    TextureResource(sf::Texture texture);

    sf::Texture m_SfTexture;

}; // class TextureResource

} // namespace dusk

#endif // DUSK_TEXTURE_RESOURCE_HPP