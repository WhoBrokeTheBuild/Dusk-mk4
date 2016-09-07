#include "Program.hpp"

namespace dusk
{

Program::Program()
    : mp_Window(nullptr)
    , mp_ResourceLibrary(nullptr)
{
}

Program::~Program()
{
    Term();
}

void Program::Run()
{
    Load();

    while (mp_Window->IsOpen())
    {
        Update();

        PreRender();
        Render();
        PostRender();
    }

    Unload();
}

Window* Program::GetWindow()
{
    return mp_Window.get();
}

ResourceLibrary* Program::GetResourceLibrary()
{
    return mp_ResourceLibrary.get();
}

RenderContext* Program::GetRenderContext()
{
    return mp_Window->GetRenderContext();
}

void Program::Init(int argc, char** argv)
{
    if (!GetWindow())
    {
        SetWindow(new Window(640, 480, "Dusk"));
    }
}

void Program::Term()
{
}

void Program::Load()
{
    mp_Window->Show();
}

void Program::Unload()
{
    mp_Window->Hide();
}

void Program::Update()
{
    mp_Window->Update();
}

void Program::PreRender()
{
    GetRenderContext()->Clear();
}

void Program::Render()
{
}

void Program::PostRender()
{
    GetRenderContext()->Display();
}

void Program::SetWindow(Window* pWindow)
{
    mp_Window.reset(pWindow);
}

void Program::SetResourceLibrary(ResourceLibrary* pResourceLibrary)
{
    mp_ResourceLibrary.reset(pResourceLibrary);
}

} // namespace dusk
