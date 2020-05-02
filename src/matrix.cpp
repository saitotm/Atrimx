#include <math.h>
#include "matrix.hpp"
//行列xベクトル
void matmul(float *matrix, float *x, int length, float *y)
{

    for (int i = 0; i < length; ++i)
    {
        y[i] = 0;
        for (int j = 0; j < length; ++j)
        {
            y[i] += matrix[length * i + j] * x[j];
        }
    }
}

//内積を求める
float dotProduct(const float *x, const float *y, int length)
{
    float result = 0;
    for (int i = 0; i < length; ++i)
    {
        result += x[i] * y[i];
    }
    return result;
}

//ベクトルのノルムを計算する
float norm(const float *x, int length)
{
    float norm = 0;
    for (int i = 0; i < length; ++i)
    {
        norm += x[i] * x[i];
    }
    return sqrt(norm);
}

//ベクトルを正規化する
void normalize(float *x, int length)
{
    float n = norm(x, length);
    for (int i = 0; i < length; ++i)
    {
        x[i] /= n;
    }
}