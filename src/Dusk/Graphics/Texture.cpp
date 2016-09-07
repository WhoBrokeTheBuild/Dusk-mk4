#include "Texture.hpp"
#include <Dusk/Graphics/RenderContext.hpp>

namespace dusk
{

bool Texture::Load(const string& filename)
{
    return m_SfTexture.loadFromFile(filename);
}

sf::Texture& Texture::GetSfTexture()
{
    return m_SfTexture;
}

sf::Texture Texture::GetSfTexture() const
{
    return m_SfTexture;
}

} // namespace dusk
