#include "StackList.h"

int main()
{
  cout << "Test Stack on List" << endl << "\nEnter maxsize stack: ";
  int n;
  cin >> n;
  try
  {
    TStackList<int> stack(n);
    for (int i = 1; i <= n; i++)
    {
      cout << "\nPut element of the Stack: " << i;
      stack.Put(i);
    }

    cout << "\n\n\nStack :\n";
    stack.Print();
    cout << endl << endl;
  
    while (!stack.IsEmpty())
     cout << "\nGet element of the Stack: " << stack.Get();
    cout << "\n\nStack is Empty.";
  }

  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}