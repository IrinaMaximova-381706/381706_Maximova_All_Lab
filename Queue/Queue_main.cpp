#include "Queue.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки структуры типа очереди\n\n";
  int n;
  cout << "Введите размер очереди\n";
  cin >> n;
  try
  {
    TQueue<int> q(n);
    for (int i = 0; i < n; i++)
    {
      q.Put(i);
      cout << "Положили значение " << i << endl;
    }

    while (!q.IsEmpty())
    {
      n = q.Get();
      cout << "Взяли " << n << endl;
    }
  }
  catch (MyException exp)
  {
    exp.Print();
  }
    return 0;
  }
