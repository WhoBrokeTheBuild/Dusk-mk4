#ifndef DUSK_RESOURCE_LIBRARY_HPP
#define DUSK_RESOURCE_LIBRARY_HPP

#include <Dusk/Types.hpp>
#include <Dusk/Resources/Resource.hpp>
#include <functional>
#include <unordered_map>

namespace dusk
{

class ResourceLibrary
{
public:

    typedef std::function<Resource*(const string&)> LoadFunc;

    bool Load(const string& filename, const string& id = "");

    void AddLoader(const string& extension, LoadFunc function);

    template <class _Type>
    _Type* GetResource(const string& id);

private:

    std::unordered_map<string, LoadFunc> m_Loaders;
    std::unordered_map<string, shared_ptr<Resource>> m_Resources;

}; // class ResourceLibrary

} // namespace dusk

#endif // DUSK_RESOURCE_LIBRARY_HPP
