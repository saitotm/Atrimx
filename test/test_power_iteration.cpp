#include <stdio.h>
#include <time.h>
#include <math.h>
#include "../src/power_iteration.hpp"

#define N (long)40000

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

    printf("lambda = %.10e\n", lambda);

    delete x, y, matrix;
    return 0;
}