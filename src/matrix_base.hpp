#ifndef _MATRIX_BASE_HPP_
#define _MATRIX_BASE_HPP_

namespace Atrimx
{

    template <typename Derived>
    class MatrixBase
    {
    public:
        typedef typename internal::traits<Derived>::Scalar Scalar;

        Derived &derived() { return *static_cast<Derived *const>(this); }
        const Derived &derived() const { return *static_cast<const Derived *const>(this); }
        Scalar operator()(int x, int y) const { return derived().operator()(x, y); }
        Scalar &operator()(int x, int y) { return derived().operator()(x, y); }
        int rows() const { return derived().rows(); }
        int cols() const { return derived().cols(); }

        template <typename OtherDerived>
        const Add<Scalar, Derived, OtherDerived>
        operator+(const MatrixBase<OtherDerived> &other) const
        {
            return Add<Scalar, Derived, OtherDerived>(derived(), other.derived());
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

} // namespace Atrimx

#endif