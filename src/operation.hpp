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
    } // namespace internal

    template <typename _Scalar, typename _LhsType, typename _RhsType>
    class Add : public MatrixBase<Add<_Scalar, _LhsType, _RhsType>>
    {
    private:
        _LhsType _lhs;
        _RhsType _rhs;

    public:
        Add(const _LhsType &lhs, const _RhsType &rhs) : _lhs(lhs), _rhs(rhs){};
        inline _Scalar operator()(int x, int y) const { return _lhs(x, y) + _rhs(x, y); }
        //_Scalar &operator()(int x, int y) { return _lhs(x, y) + _rhs(x, y); }
    };

    //template <typename _Scalar, type
    //class Unary : public MatrixBase<_Scalar, >
} // namespace Atrimx

#endif