#ifndef _INCLUDE_MATRIX_HPP_
#define _INCLUDE_MATRIX_HPP_

void matmul(float *matrix, float *x, int length, float *y);
float dotProduct(const float *x, const float *y, int length);
float norm(const float *x, int length);
void normalize(float *x, int length);

#endif