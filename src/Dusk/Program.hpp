#ifndef DUSK_PROGRAM_HPP
#define DUSK_PROGRAM_HPP

#include <Dusk/Graphics/RenderContext.hpp>
#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Resources/ResourceLibrary.hpp>
#include <Dusk/Types.hpp>

namespace dusk
{

/// The central program class that orchestrates the application
/** The construct that handles creating the window, resource loader, etc. as
 *  well as providing overrides for a custom application to hook into.
 */
class Program
{
public:
    Program(const Program&) = delete;

    Program();
    virtual ~Program();

    /// The function fired upon construction of the program instance.
    /** This creates the window, resource loader, etc. but does not load any content.
     */
    virtual void Init(int argc, char** argv);

    /// The main application loop, this will call Init(), Update(), Render() and Term() functions
    /** This function calls Init() first, then loops for as long as the window is open. During that
     *  loop, it calls Update(), followed by PreRender(), Render(), and PostRender() in that order.
     *  Once the window is closed, this function will call Term()
     */
    virtual void Run();

    Window* GetWindow();
    ResourceLibrary* GetResourceLibrary();
    RenderContext* GetRenderContext();

protected:
    /// The function fired upon destruction of the program instance.
    /** This calls any cleanup functions related to the window, resource loader, or any other
     *  internal classes. This does not handle unloading of content, see Unload()
     */
    virtual void Term();

    /// The function fired when Run() is invoked, that loads content and shows the window.
    /** This calls the window's show function, and allows loading of resources (textures, audio, etc)
     */
    virtual void Load();

    /// The function fired when Run() is finishing, that unloads content and hides the window.
    /** This calls the window's hide function, and allows unloading of resources loaded by Load()
     */
    virtual void Unload();

    /// The main update function of the program, called by the Run() function every frame
    /** This triggers updates of the window, input, and all other entities. This does not cause any
     *  direct updates to what's on screen, that should be handled by the Render() function.
     */
    virtual void Update();

    /// The pre-render function of the program, called just before Render()
    /** This is used to clear the screen, and prepare it for rendering.
     */
    virtual void PreRender();

    /// The main render function of the program, called by the Run() function every frame
    /** This allows for draw methods to be called on the context. This should not be used for any
     *  updating of objects, but just rendering them.
     */
    virtual void Render();

    /// The post-render function of the program, called just after Render()
    /** This is used to flip the buffers, and cause the changes that have been rendered to appear on
     *  the screen.
     */
    virtual void PostRender();

    /// Update the window pointer, deleting the old one
    void SetWindow(Window* pWindow);

    /// Update the loader pointer, deleting the old one
    void SetResourceLibrary(ResourceLibrary* pResourceLibrary);

private:
    unique_ptr<Window> mp_Window;
    unique_ptr<ResourceLibrary> mp_ResourceLibrary;

}; // class Program

} // namespace dusk

#endif // DUSK_PROGRAM_HPP
