#include "Exceptions.h"
const char* bad_range::what() const noexcept{
    return "exception caught";
}
const char* bad_lenght::what() const noexcept{
    return "exception caught";
}