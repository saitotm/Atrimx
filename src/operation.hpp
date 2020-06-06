#ifndef __OPERATION_HPP__
#define __OPERATION_HPP__

#include "matrix_base.hpp"

namespace Atrimx
{
    namespace internal
    {
        template <typename _Scalar, typename _LhsType, typename _RhsType>
        struct traits<Add<_Scalar, _LhsType, _RhsType>>
        {
            typedef _Scalar Scalar;
        };
        template <typename _Scalar, typename _LhsType, typename _RhsType>
        struct traits<Sub<_Scalar, _LhsType, _RhsType>>
        {
            typedef _Scalar Scalar;
        };

        template <typename _LhsType, typename _Scalar>
        struct traits<ProductScalar<_LhsType, _Scalar>>
        {
            typedef _Scalar Scalar;
        };

        template <typename _Scalar, typename _LhsType, typename _RhsType>
        struct traits<ProductMatrix<_Scalar, _LhsType, _RhsType>>
        {
            typedef _Scalar Scalar;
        };

    } // namespace internal

    template <typename _Scalar, typename _LhsType, typename _RhsType>
    class Add : public MatrixBase<Add<_Scalar, _LhsType, _RhsType>>
    {
    private:
        _LhsType lhs_;
        _RhsType rhs_;

    public:
        Add(const _LhsType &lhs, const _RhsType &rhs) : lhs_(lhs), rhs_(rhs){};
        inline _Scalar operator()(int x, int y) const { return lhs_(x, y) + rhs_(x, y); }
        //_Scalar &operator()(int x, int y) { return lhs_(x, y) + rhs_(x, y); }
    };

    template <typename _Scalar, typename _LhsType, typename _RhsType>
    class Sub : public MatrixBase<Sub<_Scalar, _LhsType, _RhsType>>
    {
    private:
        _LhsType lhs_;
        _RhsType rhs_;

    public:
        Sub(const _LhsType &lhs, const _RhsType &rhs) : lhs_(lhs), rhs_(rhs){};
        inline _Scalar operator()(int x, int y) const { return lhs_(x, y) - rhs_(x, y); }
    };

    template <typename _Scalar, typename _LhsType, typename _RhsType>
    class ProductMatrix : public MatrixBase<ProductMatrix<_Scalar, _LhsType, _RhsType>>
    {
    private:
        _LhsType lhs_;
        _RhsType rhs_;

    public:
        ProductMatrix(const _LhsType &lhs, const _RhsType &rhs) : lhs_(lhs), rhs_(rhs) {}
        inline _Scalar operator()(int x, int y) const
        {
            _Scalar result = 0;
            for (int i = 0; i < lhs_.cols(); ++i)
            {
                result = lhs_(x, i) * rhs_(i, y);
            }
            return result;
        }
    };

    template <typename _LhsType, typename _Scalar>
    class ProductScalar : public MatrixBase<ProductScalar<_LhsType, _Scalar>>
    {
    private:
        _LhsType lhs_;
        _Scalar scalar_;

    public:
        ProductScalar(const _LhsType &lhs, const _Scalar &scalar) : lhs_(lhs), scalar_(scalar) {}
        inline _Scalar operator()(int x, int y) const { return lhs_(x, y) * scalar_; }
    };

    //template <typename _Scalar, type
    //class Unary : public MatrixBase<_Scalar, >
} // namespace Atrimx

#endif