#ifndef glt_array
#define glt_array

#include <array>

namespace glt {

/* Multi-dimensional array class
 */
template <typename T, std::size_t Dn, std::size_t... D>
class array : public array<std::array<T, Dn>, D...> {};

template <typename T, std::size_t Dn>
class array<T, Dn> : public std::array<T, Dn> {};

}  // namespace glt

#endif
