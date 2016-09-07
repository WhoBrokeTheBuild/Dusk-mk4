#ifndef DUSK_LOG_HPP
#define DUSK_LOG_HPP

#include <cstdio>

namespace dusk
{

#define LOG_MSG(FMT, ...) fprintf(stdout, FMT, __VA_ARGS__)
#define LOG_ERR(FMT, ...) fprintf(stderr, FMT, __VA_ARGS__)

} // namespace dusk

#endif // DUSK_LOG_HPP
