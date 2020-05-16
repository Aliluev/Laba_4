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
        result.massiv[i]=result[i] + (matrix[i][j] * vector[j]);

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
  if (matrix.GetN() == vector.GetRazmer() && matrix.GetM() == 1)
  {
    T** arr = new T * [matrix.GetN()];
    for (int i = 0; i < vector.GetRazmer(); i++)
      arr[i] = new T[vector.GetRazmer()];

    for (int i = 0; i < vector.GetRazmer(); i++)
      for (int j = 0; j < matrix.GetN(); j++)
      {
       /* result.SetRazmernost(i, j);
          result.s[i]=(matrix[0][j] * vector[i]);*/
          arr[i][j]= (matrix[0][j] * vector[i]);
      }
    Matric<T> result(matrix.GetN(), vector.GetRazmer(), arr);


    for (int i = 0; i < vector.GetRazmer(); i++)
      delete[] arr[i];
    delete[] arr;
    return result;
  }
  else
    throw - 1;
};