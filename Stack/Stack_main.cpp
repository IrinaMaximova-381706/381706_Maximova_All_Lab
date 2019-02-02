#include "Stack.h"


int main()
{
  cout << "Test Stack" << endl << "\nEnter size stack: ";
  int n;
  cin >> n;
  try
  {
    TStack<int> stack(n);
    for (int i = 0; i < n; i++)
      stack.Put(i);

    cout << "\nStack :\n";
    stack.PrintStack();

    TStack<int> copyStack(stack);
    cout << "\n\nCopyStack :\n";
    copyStack.PrintStack();

    if (copyStack == stack)
    cout << "\n\nCopyStack and Stack equivalence";

    cout << "\n\nGet element of the Stack: " << stack.Get();

    cout << "\n\nStack now:\n";
    stack.PrintStack();

    if (copyStack != stack)
      cout << "\n\nCopyStack and Stack different\n";
  }

  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}