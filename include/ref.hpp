#ifndef REF_HPP
#define REF_HPP

#include <array>
#include <ostream>

namespace alias
{
// template <size_t N = 4, typename T = float, size_t M = N>
// using mat = std::array<T, N * M>;

// template <size_t N, typename T> using vec = mat<N, T, 1>;

typedef std::array<float, 16> mat4;

std::ostream& operator <<(std::ostream& out, const mat4& v);
mat4          operator *(const mat4& a, const mat4& b);

}

namespace cStyle
{

// Matrix
template<size_t N, size_t M = N, typename T = int>
struct s_mat
{
    const size_t n = N;
    const size_t m = M;
    T            e[N * M];
};

template<size_t N, size_t M = N, typename T = int>
using cmr = const s_mat<N, M, T>&;

// Operator
template<size_t N, size_t M = N, typename T = int>
s_mat<N, M, T>& add(const s_mat<N, M, T>& a, const s_mat<N, M, T>&);

// Vector
template<size_t N, typename T = int>
using s_vec = s_mat<N, 1, T>;

}
#endif
