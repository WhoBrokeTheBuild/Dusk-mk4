#include "ResourceLibrary.hpp"

#include <Dusk/Graphics/Resources/FontResource.hpp>
#include <Dusk/Graphics/Resources/TextureResource.hpp>
#include <Dusk/Logging/Log.hpp>

namespace dusk
{

ResourceLibrary::ResourceLibrary()
{
    AddLoader("png", LoadTextureResource);
    AddLoader("jpg", LoadTextureResource);
    AddLoader("jpeg", LoadTextureResource);
    AddLoader("gif", LoadTextureResource);

    AddLoader("ttf", LoadFontResource);
}

ResourceLibrary::~ResourceLibrary()
{
}

bool ResourceLibrary::Load(const string& filename, string id /*= ""*/)
{
    size_t lastDot = filename.rfind('.');
    if (lastDot == string::npos || lastDot == filename.size() - 1)
    {
        LOG_ERR("Unable to read extension of file: '%s'\n", filename.c_str());
        return false;
    }

    string ext = filename.substr(lastDot + 1);
    auto loader = m_Loaders.find(ext);
    if (loader == m_Loaders.end())
    {
        LOG_ERR("Unable to find loader for extension: '%s'\n", ext.c_str());
        return false;
    }

    Resource* pResource = loader->second(filename);
    if (!pResource)
    {
        LOG_ERR("Failed to load resource: '%s'\n", filename.c_str());
        return false;
    }

    if (id.empty())
    {
        id = filename;
    }

    LOG_MSG("Successfully loaded resource: '%s'\n", filename.c_str());
    m_Resources.emplace(id, pResource);
    return true;
}

void ResourceLibrary::AddLoader(const string& extension, LoadFunc function)
{
    m_Loaders.emplace(extension, function);
}

} // namespace dusk
