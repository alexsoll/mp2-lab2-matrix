// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a = b" << endl << c << endl;

  TVector<int> v1(3), v2(3);
  cout << "введите вектор 1 и 2";
  for (i = 0; i < 3; i++) {
	  cin >> v1[i];
  }
  for (i = 0; i < 3; i++) {
	  cin >> v2[i];
  }
  cout << "v1 * v2 = " << v1 * v2 << endl;
  cout << "v1 * 3 = " << v1 * 3 << endl;
  cout << "v2 * 3 = " << v2 * 3 << endl;
  cout << "v2 + 10 = " << v2 + 10 << endl;
  cout << "v1 + v2 = " << v1 + v2 << endl;
  if (v1 == v2)
	  cout << "вектора равны" << endl;
  else 
	  cout << "вектора различны" << endl;

}
//---------------------------------------------------------------------------
