#include "Vector.h"

int main()
{

  cout << "Vectors:";
  try
  {
    TVector <int> V1(3), V2(3), R(3);
    for (int i = 0; i < 3; i++)
    {
      V1[i] = (i + 1 - (i + 3) * 3);
      V2[i] = (i * 10 + 5 - i) * 2;
    }
    cout << "\n\nV1: " << V1 << endl;
    cout << "V2: " << V2 << endl;

    cout << "\n\nArithmetic operations:\n\n";

    R = V1 + V2;
    cout << "Result V1 + V2: " << R << endl;

    R = V1 - V2;
    cout << "Result V1 - V2: " << R << endl;

    int k = V1 * V2;
    cout << "Result V1 * V2: " << k << endl;

    cout << "\n\nUsing input / output streams:\n";
    TVector <int> V(5);
    cin >> V;
    cout << "\nVector entered by you: " << V << endl;
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}
