#include "Matrix.h"

int main()
{
  cout << "Creating matrix\n\n";
  TMatrix<int> M1(3), M2(3), R(3), MCin(3);
  int k = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3 - i; j++)
      M1[i][j] = k++;

  M2[0][0] = 1;
  M2[0][1] = 2;
  M2[0][2] = 3;
  M2[1][0] = 1;
  M2[1][1] = 2;
  M2[2][0] = 1;

  cout << "M1:" << endl << M1 << endl;
  cout << "\nM2:" << endl << M2 << endl;

  cout << "Examples of arithmetic operations: \n\n";
  try {
    R = M1 + M2;
    cout << "Result M1 + M2:" << endl << R << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    R = M1 - M2;
    cout << "Result M1 - M2:" << endl << R << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    R = M1 * M2;
    cout << "Result M1 * M2:" << endl << R << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }
  
   try {
    R = M1 / M2;
    cout << "Result M1 * M2:" << endl << R << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  cout << "\n\nUsing input / output streams:\n";
  cin >> MCin;
  cout << "\nMatrix:" << endl << MCin;
  return 0;
}
