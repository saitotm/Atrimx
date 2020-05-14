#include <iostream>
#include "atrimx.hpp"
int main()
{
    Atrimx::Matrix<float, 3, 4> m1, m2;
    for (int i = 0; i < m1.rows(); ++i)
    {
        for (int j = 0; j < m1.cols(); ++j)
        {
            m1(i, j) = m1.rows() * i + j;
            m2(i, j) = 3;
        }
    }

    std::cout << m1.toString() << std::endl;
    std::cout << m2.toString() << std::endl;

    Atrimx::Matrix<float, 3, 4> m3;
    m3 = m1 + m2;
    std::cout << m3.toString() << std::endl;
}