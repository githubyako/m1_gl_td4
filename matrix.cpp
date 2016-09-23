#include "matrix.hpp"

template<typename T> Matrix<T>::Matrix()
{
    
}

template<typename T> Matrix<T>::Matrix(const Matrix<T>& _m):m_mat(_m.getMat().size())
{
    
}

template<typename T> Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols)
{
}

template<typename T> const Matrix<T> & Matrix<T>::operator*(const Matrix<T>& _m)
{
}

template<typename T> void Matrix<T>::operator=(const Matrix<T>& _m)
{
}

template<typename T> T Matrix<T>::sum()
{
}

template<typename T> void Matrix<T>::invert()
{
}

