#include <iostream>
#include "../src/atrimx.hpp"
namespace
{
    const int kCols = 100;
    const int kRows = 200;
} // namespace

int main()
{
    Atrimx::Matrix<float, kRows, kCols> m1, m2;
    for (int i = 0; i < m1.rows(); ++i)
    {
        for (int j = 0; j < m1.cols(); ++j)
        {
            m1(i, j) = m1.rows() * i + j;
            m2(i, j) = -(i * j % 3);
        }
    }

    // 行と列のサイズが一致しなくともエラーが出ない
    Atrimx::Matrix<float, kRows, kCols> m_add;
    m_add = m1 + m2;
    Atrimx::Matrix<float, kRows, kCols> m_sub;
    m_sub = m1 - m2;

    for (int i = 0; i < kRows; ++i)
    {
        for (int j = 0; j < kCols; ++j)
        {
            float elm1 = m_add.rows() * i + j;
            float elm2 = -(i * j % 3);
            float elm_add = elm1 + elm2;

            float diff = abs(m_add(i, j) - elm_add);
            if (diff > 1e-6)
            {
                std::cout << "error_add " << i << ", " << j << std::endl;
            }

            float elm_sub = elm1 - elm2;
            diff = abs(m_sub(i, j) - elm_sub);
            if (diff > 1e-6)
            {
                std::cout << "error_sub " << i << ", " << j << std::endl;
            }
        }
    }
    std::cout << "finished" << std::endl;
}