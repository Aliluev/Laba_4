#pragma once
#include "Vector.h"
#include "Matrix.h"
template <class T>
MyVector<T> operator *(Matric<T>& matrix, MyVector<T>& vector)
{
  if (matrix.GetM() == vector.GetM())
  {
    T* arr = new T[matrix.GetN()];
    MyVector<T> result(matrix.GetN(), arr);


    for (int i = 0; i < result.GetM(); i++)
    {
      result.massiv[i]=0;
      for (int j = 0; j < vector.GetM(); j++)
      {
        result.massiv[i]=result[i] + (matrix[i][j] * vector[j]));

      }
    }
    delete[] arr;
    return result;
  }
  else
    throw - 1;
};

template <class T>
Matric<T> operator *(MyVector<T>& vector, Matric<T>& matrix)
{
  if (matrix.GetN() == vector.GetM() && matrix.GetM() == 1)
  {
    T** arr = new T * [matrix.GetN()];
    for (int i = 0; i < vector.GetM(); i++)
      massiv[i] = new T[vector.GetM()];
    Matric<T> result(matrix.GetN(), vector.GetM(), arr);

    for (int i = 0; i < result.GetM(); i++)

      for (int j = 0; j < result.GetN(); j++)
      {
        result.SetRazmernost(i, j);
        result.massiv[i]=(matrix[0][j] * vector[i]);
      }

    for (int i = 0; i < vector.GetM(); i++)
      delete[] arr[i];
    delete[] arr;
    return result;
  }
  else
    throw - 1;
};