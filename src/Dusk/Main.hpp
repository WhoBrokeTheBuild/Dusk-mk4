#ifndef DUSK_MAIN_HPP
#define DUSK_MAIN_HPP

namespace dusk
{

template <class _Program>
int Main(int argc, char** argv)
{
    _Program* prog = new _Program();
    prog->Run(argc, argv);
    delete prog;

    return 0;
}

} // namespace dusk

#endif // DUSK_MAIN_HPP
