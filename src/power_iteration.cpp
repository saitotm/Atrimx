#include <math.h>
#include <time.h>
#include <cstdio>
#include <stdio.h>
#include "matrix.hpp"

#define N (long)100000
#define EPS 1e-13

void power_iteration(float *x, float *matrix, int length, float *y, float &lambda);

int main()
{
    float *x = new float[N];
    float *y = new float[N];
    float *matrix = new float[N * N];

    // x, matrixの初期化
    for (int i = 0; i < N; ++i)
    {
        x[i] = 1;
    }

    x[0] = 1;

    srand(0);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            //matrix[N * i + j] = 0;
            matrix[N * i + j] = rand() % 100;
        }
    }

    float lambda;
    clock_t start = clock();
    power_iteration(x, matrix, N, y, lambda);
    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("\ntime %lf[s]\n", time);

    if (false)
    {
        printf("[");
        for (int i = 0; i < N; ++i)
        {
            printf("%f,\n", y[i]);
        }
        printf("]\n");
    }

    printf("lambda = %.6e\n", lambda);

    delete x, y, matrix;
    return 0;
}

//べき乗法
void power_iteration(float *x, float *matrix, int length, float *y, float &lambda)
{
    long long epochs = 0;
    int iters = 0;
    int batch_size = 1;
    float lambda0 = 0;
    while (true)
    {
        normalize(x, N);
        matmul(matrix, x, length, y);
        float lambda1 = dotProduct(y, y, length) / dotProduct(y, x, length);
        if (abs(lambda1 - lambda0) < EPS)
        {
            lambda = lambda1;
            return;
        }
        else
        {
            for (int i = 0; i < N; ++i)
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
            printf("epoch %d: lambda = %.6e\n", epochs, lambda1);
        }
    }
}