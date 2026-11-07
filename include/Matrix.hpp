#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <cstddef>
#include <string>

template<typename T>
struct result
{
    T    inner;
    bool ok;
};

// forward
template<size_t N, size_t M, typename T>
class Matrix;

template<size_t N, size_t M, typename T>
using cr_mat = const Matrix<N, M, T>&;

// Vector
template<size_t N, typename T = int>
using Vector = Matrix<N, 1, T>;

// Matrix
template<size_t N, size_t M = N, typename T = int>
class Matrix
{
  private:
    const size_t n = N;
    const size_t m = M;
    T            e[N * M];

  public:
    Matrix();
    Matrix(Matrix&&)                  = delete;
    Matrix& operator =(const Matrix&) = delete;
    Matrix& operator =(Matrix&&)      = delete;
    Matrix(const Matrix& r);
    ~Matrix();

    /* accumulator */
    // bool square() const;

    // Matrix& add(const Matrix& o) const;
    // Matrix& sub(const Matrix& o) const;
    // Matrix& scl(const Matrix& o) const;

    /* pure */

    // helper
    friend size_t len(const Matrix& m);
    friend size_t shape(const Matrix& m);
    friend bool   square(const Matrix& m);

    friend std::string   string(const Matrix& m);
    friend std::ostream& operator <<(std::ostream& out, const Matrix& v);

    // 00
    friend Matrix add(const Matrix& a, const Matrix& b);
    friend Matrix sub(const Matrix& a, const Matrix& b);
    friend Matrix scl(const Matrix& m, const T);

    // 01
    friend Vector<N, T> linear_combination(std::array<Vector<N, T>, N>, std::array<T, N>);

    // 02
    friend Vector<N, T> lerp(const Vector<N, T>& u, const Vector<N, T>& v, float t);

    // 03
    friend T dot(const Vector<N, T>& u, const Vector<N, T>& v);

    // 04
    friend float norm_1(const Vector<N, T>& v);
    friend float norm(const Vector<N, T>& v);
    friend float norm_inf(const Vector<N, T>& v);

    // 05
    friend float angle_cos(const Vector<N, T>& u, const Vector<N, T>& v);

    // 06
    friend Vector<3, T> cross(const Vector<3, T>& u, const Vector<3, T>& v);

    // 07
    friend Vector<N, T> mul_vec(const Matrix<N, M, T>& a, const Vector<M, T>& b);
    template<size_t P>
    friend Matrix<N, M, T> mul_mat(const Matrix<N, M, T>& a, const Matrix<M, P, T>& b);

    // 08
    friend Matrix<N, N, T> trace(const Matrix<N, N, T>& m);

    // 09
    friend Matrix<M, N, T> transpose(const Matrix<N, M, T>& m);

    // 10
    friend Matrix row_echelon(const Matrix& m);

    // 11
    friend T determinant(const Matrix& m);

    // 12
    friend Matrix<N, N, T>* inverse(const Matrix<N, N, T>& m);

    // 13
    friend size_t rank(const Matrix& m);

    // 14
    friend Matrix<4, 4, T> projection(float fov, float ratio, float near, float far);
};

#endif
