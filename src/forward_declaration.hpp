#ifndef _FORWARD_DECLARATION_HPP_
#define _FORWARD_DECLARATION_HPP_

namespace Atrimx
{
    namespace internal
    {
        template <typename T>
        struct traits;
    }

    template <typename Derived>
    class MatrixBase;
    template <typename _Scalar, int _Rows, int _Cols>
    class Matrix;

    template <typename Scalar, typename LhsType, typename RhsType>
    class Add;

    template <typename _Scalar, typename _LhsType, typename _RhsType>
    class Sub;
} // namespace Atrimx

#endif