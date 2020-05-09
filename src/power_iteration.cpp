#include <stdio.h>
#include <math.h>
#include "matrix.hpp"

#define EPS 1e-10

//べき乗法
void power_iteration(float *x, float *matrix, int length, float *y, float &lambda)
{
    long long epochs = 0;
    int iters = 0;
    int batch_size = 1;
    float lambda0 = 0;
    while (true)
    {
        normalize(x, length);
        matmul(matrix, x, length, y);
        float lambda1 = dotProduct(y, y, length) / dotProduct(y, x, length);
        if (abs(lambda1 - lambda0) < abs(lambda1) * EPS)
        {
            lambda = lambda1;
            return;
        }
        else
        {
            for (int i = 0; i < length; ++i)
            {
                x[i] = y[i];
            }
            lambda0 = lambda1;
        }
        iters++;
        if (iters % batch_size == 0)
        {
            iters = 0;
            epochs++;
            printf("epoch %d: lambda = %.10e\n", epochs, lambda1);
        }
    }
}