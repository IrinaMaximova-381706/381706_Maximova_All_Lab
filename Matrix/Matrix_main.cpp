#include "Matrix.h"

int main()
{
  cout << "Creating matrix\n\n";
  TMatrix<int> M1(5), M2(5), R(5);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5 - i; j++) 
    {
      M1[i][j] = (i + 1) * (j + 1);
      M2[i][j] = (i * 10 + j + 3 + i) * 8;
    }
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

  cout << "\n\nUsing input / output streams:\n";
  TMatrix <int> MT(3);
  cin >> MT;
  cout << "\nMatrix entered by you:" << endl << MT;
  return 0;
}