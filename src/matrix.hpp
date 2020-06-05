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
        _Scalar *data_;

    public:
        Matrix() { data_ = new _Scalar[_Rows * _Cols]; }
        inline int rows() const { return _Rows; }
        inline int cols() const { return _Cols; }
        inline _Scalar operator()(int x, int y) const { return data_[cols() * x + y]; }
        inline _Scalar &operator()(int x, int y) { return data_[cols() * x + y]; }

        // 行列の文字列表現を返す
        std::string toString()
        {
            std::string result = "[";
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    result += std::to_string(operator()(i, j));
                    result += ", ";
                }
                result += "\n ";
            }
            // 末尾の", \n"の削除
            result.erase(result.end() - 4, result.end());
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
