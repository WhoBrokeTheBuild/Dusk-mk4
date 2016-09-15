
#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Graphics/Resources/TextureResource.hpp>
#include <Dusk/Resources/ResourceLibrary.hpp>
#include <Dusk/Main.hpp>
#include <Dusk/Program.hpp>

using namespace dusk;

class TestProgram : public Program
{
public:
    virtual void Init(int argc, char** argv) override
    {
        SetWindow(new Window(640, 480, "Test Window"));
        Program::Init(argc, argv);
    }

    virtual void Load() override
    {
        GetResourceLibrary()->Load("assets/test.png", "test-png");
        GetResourceLibrary()->Load("assets/test.jpg", "test-jpg");
        GetResourceLibrary()->Load("assets/Roboto.ttf");

        mp_Tex = GetResourceLibrary()->GetResource<Texture>("test-jpg");
    }

    virtual void Render() override
    {
        if (mp_Tex) {
            GetRenderContext()->Draw(mp_Tex, Vector2f(0.0f, 0.0f));
        }
    }

private:

    Texture* mp_Tex = nullptr;

};

int main(int argc, char** argv)
{
    return Main<TestProgram>(argc, argv);
}
