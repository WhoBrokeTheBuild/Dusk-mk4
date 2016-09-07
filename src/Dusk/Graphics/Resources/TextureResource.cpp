#include "TextureResource.hpp"

namespace dusk
{

Resource* LoadTextureResource(const string& filename)
{
    Texture* pTexture = new Texture();
    bool loaded = pTexture->Load(filename);
    if (!loaded)
    {
        delete pTexture;
        return nullptr;
    }

    TextureResource* pResource = new TextureResource(pTexture);
    return (Resource*)pResource;
}

TextureResource::TextureResource(Texture* pTexture)
    : mp_Texture(pTexture)
{
}

void* TextureResource::GetResource()
{
    return (void*)mp_Texture.get();
}

} // namespace dusk
