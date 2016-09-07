#include "Program.hpp"

namespace dusk
{

Program::Program()
    : mp_Window(nullptr)
    , mp_Loader(nullptr)
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
        Render();
    }

    Unload();
}

Window* Program::GetWindow()
{
    return mp_Window.get();
}

Loader* Program::GetLoader()
{
    return mp_Loader.get();
}

Context* Program::GetContext()
{
    return mp_Window->GetContext();
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

void Program::Render()
{
    GetContext()->Clear();

    GetContext()->Display();
}

void Program::SetWindow(Window* pWindow)
{
    mp_Window.reset(pWindow);
}

void Program::SetLoader(Loader* pLoader)
{
    mp_Loader.reset(pLoader);
}


} // namespace dusk
