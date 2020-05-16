#ifndef _INCLUDE_MATRIX_HPP_
#define _INCLUDE_MATRIX_HPP_

#include <string>

namespace Atrimx
{

    namespace internal
    {
        template <typename _Scalar, int _Rows, int _Cols>
        struct traits<Matrix<_Scalar, _Rows, _Cols>>
        {
            typedef _Scalar Scalar;
        };
    } // namespace internal

    template <typename _Scalar, int _Rows, int _Cols>
    class Matrix : public MatrixBase<Matrix<_Scalar, _Rows, _Cols>>
    {
    private:
        _Scalar *_data;

    public:
        Matrix() { _data = new _Scalar[_Rows * _Cols]; }
        int rows() const { return _Rows; }
        int cols() const { return _Cols; }
        _Scalar operator()(int x, int y) const { return _data[cols() * x + y]; }
        _Scalar &operator()(int x, int y) { return _data[cols() * x + y]; }

        // 行列の文字列表現を返す
        std::string toString()
        {
            std::string result = "[";
            for (int i = 0; i < rows(); ++i)
            {
                result += std::to_string(operator()(i, 0));
                for (int j = 1; j < cols(); ++j)
                {
                    result += ", ";
                    result += std::to_string(operator()(i, j));
                }
                if (i < rows() - 1)
                    result += ", \n ";
            }

            result += "]";
            return result;
        }

        template <typename OtherDerived>
        inline Matrix &operator=(const MatrixBase<OtherDerived> &other)
        {
            return MatrixBase<Matrix<_Scalar, _Rows, _Cols>>::operator=(other.derived());
        }
    };

} // namespace Atrimx

/*
void matmul(float *matrix, float *x, int length, float *y);
float dotProduct(const float *x, const float *y, int length);
float norm(const float *x, int length);
void normalize(float *x, int length);
void col(float *matrix, float *col_vec, int col_idx, int rows, int cols);
*/

#endif
