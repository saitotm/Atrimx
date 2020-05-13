#ifndef _MATRIX_BASE_HPP_
#define _MATRIX_BASE_HPP_

template <typename Derived, typename Scalar, int Rows, int Cols>
class MatrixBase
{
public:
    Derived &derived() { return *static_cast<Derived *const>(this); }
    const Derived &derived() const { return *static_cast<const Derived *const>(this); }
    Scalar operator()(int x, int y) { return derived().operator()(x, y); }
    int rows() const { return Rows; }
    int cols() const { return Cols; }
};

#endif