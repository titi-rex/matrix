#include "Matrix.hpp"

template<size_t N, size_t M = N, typename T = int>
size_t len(const Matrix<N, M, T>& m)
{ return m.n * m.m; };

template<size_t N, size_t M = N, typename T = int>
Matrix<N, M, T> add(const Matrix<N, M, T>& a, const Matrix<N, M, T>& b)
{
    return a;
};


void cppTest(void)
{
    Vector<3> a;
    Vector<3> b;
    Vector<4> c;
    Vector<4> d;

    Matrix<3, 4> g;
    Matrix<4, 3> h;

    auto r = mul_mat(g, h);

    auto r3 = lerp(a, b, 2.0);
    auto r4 = lerp(c, d, 2.0);



}
