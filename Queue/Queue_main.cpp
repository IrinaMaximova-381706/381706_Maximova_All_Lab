#include "Queue.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  cout << "An example of working with a queue data structure\n\n";
  int n;
  cout << "Enter size queue\n";
  cin >> n;
  try
  {
    TQueue<int> q(n);
    for (int i = 0; i < n; i++)
    {
      q.Put(i);
      cout << "Put " << i << endl;
    }

    while (!q.IsEmpty())
    {
      n = q.Get();
      cout << "Get " << n << endl;
    }
  }
  catch (MyException exp)
  {
    exp.Print();
  }
    return 0;
  }
