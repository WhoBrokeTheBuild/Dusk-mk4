#ifndef DUSK_TEXTURE_HPP
#define DUSK_TEXTURE_HPP

#include <Dusk/Types.hpp>
#include <SFML/Graphics.hpp>

namespace dusk
{

class RenderContext;

class Texture
{

    friend class RenderContext;

public:
    Texture() = default;
    Texture(const Texture&) = delete;
    virtual ~Texture() = default;

    bool Load(const string& filename);

protected:
    sf::Texture& GetSfTexture();
    sf::Texture GetSfTexture() const;

    sf::Texture m_SfTexture;

}; // class Texture

} // namespace dusk

#endif // DUSK_TEXTURE_HPP
