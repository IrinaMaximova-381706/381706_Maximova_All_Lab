#include "List.h"

int main()
{
  try
  {
    TList<int> list;
    cout << "\nEnter the number of elements you want to enter at the beginning at the List: ";
    int beg, end;
    cin >> beg;
    for (int i = 1; i <= beg; i++)
      list.PutBegin(i);
    cout << "\nEnter the number of elements you want to enter at the end at the List: ";
    cin >> end;
    for (int i = 1; i <= end; i++)
      list.PutEnd(i);

    cout << "\n\nThe List create:\n";
    list.Print();

    cout << "\n\nElement at the top of the List: " << list.GetBegin();
    cout << "\nElement at the end of the List: " << list.GetEnd();

    cout << "\n\nThe List is currently:\n";
    list.Print();
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}

