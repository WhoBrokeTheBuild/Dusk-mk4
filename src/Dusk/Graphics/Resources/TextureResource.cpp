#include "TextureResource.hpp"

namespace dusk
{

Resource* LoadTextureResource(const string& filename)
{
    sf::Texture texture;
    texture.loadFromFile(filename);

    TextureResource* pResource = new TextureResource(texture);
    return (Resource*)pResource;
}

TextureResource::TextureResource(sf::Texture texture)
    : m_SfTexture(texture)
{
}

} // namespace dusk
