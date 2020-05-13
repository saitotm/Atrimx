#ifndef _INCLUDE_MATRIX_HPP_
#define _INCLUDE_MATRIX_HPP_

#include "matrix_base.hpp"
#include <string>

template <typename Scalar, int Rows, int Cols>
class Matrix : public MatrixBase<Matrix<Scalar, Rows, Cols>, Scalar, Rows, Cols>
{
private:
    Scalar *_data;

public:
    Matrix() { _data = new Scalar[Rows * Cols]; }
    Scalar operator()(int x, int y) const { return _data[Cols * x + y]; }
    Scalar &operator()(int x, int y) { return _data[Cols * x + y]; }

    // 行列の文字列表現を返す
    std::string toString()
    {
        std::string result = "[";
        for (int i = 0; i < Rows; ++i)
        {
            if (i > 0)
                result += " ";
            for (int j = 0; j < Cols; ++j)
            {
                result += std::to_string(_data[i, j]);
                if (i < Rows - 1 || j < Cols - 1)
                    result += ", ";
            }
            if (i < Rows - 1)
                result += "\n";
        }

        result += "]";
        return result;
    }
};

void matmul(float *matrix, float *x, int length, float *y);
float dotProduct(const float *x, const float *y, int length);
float norm(const float *x, int length);
void normalize(float *x, int length);
void col(float *matrix, float *col_vec, int col_idx, int rows, int cols);

#endif