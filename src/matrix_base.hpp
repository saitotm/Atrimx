#ifndef _MATRIX_BASE_HPP_
#define _MATRIX_BASE_HPP_

namespace Atrimx
{

    template <typename Derived>
    class MatrixBase
    {
    public:
        typedef typename internal::traits<Derived>::Scalar Scalar;

        inline Derived &derived() { return *static_cast<Derived *const>(this); }
        inline const Derived &derived() const { return *static_cast<const Derived *const>(this); }
        inline Scalar operator()(int x, int y) const { return derived().operator()(x, y); }
        inline Scalar &operator()(int x, int y) { return derived().operator()(x, y); }
        inline int rows() const { return derived().rows(); }
        inline int cols() const { return derived().cols(); }

        template <typename OtherDerived>
        inline const Add<Scalar, Derived, OtherDerived>
        operator+(const MatrixBase<OtherDerived> &other) const
        {
            return Add<Scalar, Derived, OtherDerived>(derived(), other.derived());
        }

        template <typename OtherDerived>
        inline const Sub<Scalar, Derived, OtherDerived>
        operator-(const MatrixBase<OtherDerived> &other) const
        {
            return Sub<Scalar, Derived, OtherDerived>(derived(), other.derived());
        }

        inline const ProductScalar<Derived, Scalar>
        operator*(const Scalar &scalar) const
        {
            return ProductScalar<Derived, Scalar>(derived(), scalar);
        }

        template <typename OtherDerived>
        Derived &operator=(const MatrixBase<OtherDerived> &other)
        {
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    operator()(i, j) = other.operator()(i, j);
                }
            }
            return derived();
        }
    };

    template <typename Derived>
    inline ProductScalar<Derived, typename internal::traits<Derived>::Scalar>
    operator*(const typename internal::traits<Derived>::Scalar &scalar, const MatrixBase<Derived> &rhs)
    {
        return ProductScalar<Derived, typename internal::traits<Derived>::Scalar>(rhs.derived(), scalar);
    }
} // namespace Atrimx

#endif