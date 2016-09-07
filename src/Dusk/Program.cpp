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
    if (!mp_Window)
    {
        mp_Window.reset(new Window(640, 480, "Hello"));
    }
}

void Program::Term()
{
    mp_Window.reset(nullptr);
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

} // namespace dusk
