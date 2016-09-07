
#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Main.hpp>
#include <Dusk/Program.hpp>

class TestProgram : public dusk::Program
{
public:
    virtual void Init(int argc, char** argv) override
    {
        mp_Window.reset(new dusk::Window(1024, 768, "Test Window"));
        dusk::Program::Init(argc, argv);
    }
};

int main(int argc, char** argv)
{
    return dusk::Main<TestProgram>(argc, argv);
}
