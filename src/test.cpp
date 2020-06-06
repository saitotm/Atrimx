#include <iostream>
#include "atrimx.hpp"
int main()
{
    Atrimx::Matrix<float, 4, 4> m1, m2;
    for (int i = 0; i < m1.rows(); ++i)
    {
        for (int j = 0; j < m1.cols(); ++j)
        {
            m1(i, j) = m1.rows() * i + j;
            m2(i, j) = 3;
        }
    }

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    Atrimx::Matrix<float, 4, 4> m3;
    m3 = m1 * m2;

    std::cout << m3 << std::endl;
}