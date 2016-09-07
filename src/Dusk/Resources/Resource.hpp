#ifndef DUSK_RESOURCE_HPP
#define DUSK_RESOURCE_HPP

namespace dusk
{

class Resource
{
public:

    Resource(const Resource&) = delete;
    virtual ~Resource() = default;

    virtual void* GetResource() = 0;

protected:

    Resource() = default;

}; // class Resource

} // namespace dusk

#endif // DUSK_RESOURCE_HPP
