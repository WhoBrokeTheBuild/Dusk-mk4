#ifndef DUSK_RESOURCE_LIBRARY_HPP
#define DUSK_RESOURCE_LIBRARY_HPP

#include <Dusk/Resources/Resource.hpp>
#include <Dusk/Types.hpp>
#include <functional>
#include <unordered_map>

namespace dusk
{

class ResourceLibrary
{
public:
    typedef std::function<Resource*(const string&)> LoadFunc;

    ResourceLibrary(const ResourceLibrary&) = delete;

    ResourceLibrary();
    virtual ~ResourceLibrary();

    bool Load(const string& filename, string id = "");

    void AddLoader(const string& extension, LoadFunc function);

    template <class _Type>
    _Type* GetResource(const string& id)
    {
        Resource* pResource = m_Resources[id].get();
        return static_cast<_Type*>(pResource->GetResource());
    }

private:
    std::unordered_map<string, LoadFunc> m_Loaders;
    std::unordered_map<string, unique_ptr<Resource> > m_Resources;

}; // class ResourceLibrary

} // namespace dusk

#endif // DUSK_RESOURCE_LIBRARY_HPP
