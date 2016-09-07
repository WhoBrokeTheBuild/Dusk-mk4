
#include <Dusk/Graphics/Window.hpp>
#include <Dusk/Main.hpp>
#include <Dusk/Program.hpp>

using namespace dusk;

class TestProgram : public Program
{
public:
    virtual void Init(int argc, char** argv) override
    {
        SetWindow(new Window(1024, 768, "Test Window"));
        Program::Init(argc, argv);
    }
};

int main(int argc, char** argv)
{
    return Main<TestProgram>(argc, argv);
}
