#include "Polish.h"
#include <cstdlib>

int GetPrt(const char op)
{
  switch (op)
  {
  case '(':
    return 1;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    return -1;
  }
}

bool IsOp(char a)
{
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

TQueue<char> ConvertToPol(string s)
{
  TQueue<char> Q(s.size() * 3);
  TStack<char> S(s.size() * 3);
  for (int i = 0; i < s.size(); i++)
  {
    if (i == 0)
      if (s[0] == '-') 
      {
        Q.Put('[');
        Q.Put('0');
        Q.Put(']');
      }
    if (isdigit(s[i]))
    {
      Q.Put('[');
      while ((i < s.size()) && isdigit(s[i + 1]))
      {
        Q.Put(s[i]);
        i++;
      }
      Q.Put(s[i]);
      Q.Put(']');
    }
    else if (S.IsEmpty())
      S.Put(s[i]);
    else if (IsOp(s[i]))
    {
      if (s[i] == '(')
        S.Put(s[i]);
      else if (s[i] == ')')
      {
        while (S.Top() != '(')
          Q.Put(S.Get());
        S.Get();
      }
      else
      {
        int p = GetPrt(s[i]);
        if (p > GetPrt(S.Top()))
          S.Put(s[i]);
        else if (p <= GetPrt(S.Top()))
        {
          while (!S.IsEmpty() && p <= GetPrt(S.Top()))
            Q.Put(S.Get());
          S.Put(s[i]);
        }
      }
    }
  }
  while (!S.IsEmpty())
    Q.Put(S.Get());
  return Q;
}

double Rez(TQueue<char> q)
{
  double res = 0;
  TStack<double> S(q.GetSize());
  while (!q.IsEmpty())
  {
    char A = q.Get();
    if (A == '[')
    {
      A = q.Get();
      double tmp = std::atof(&A);
      while (q.Top() != ']' && !q.IsEmpty())
      {
        A = q.Get();
        tmp = tmp * 10 + std::atof(&A);
      }
      q.Get();
      S.Put(tmp);
    }
    if (IsOp(A))
    {
      double B = S.Get();
      double C = S.Get();
      double D = 0;
      if (A == '+')
        D = C + B;
      if (A == '-')
        D = C - B;
      if (A == '*')
        D = C * B;
      if (A == '/')
        D = C / B;
      S.Put(D);
    }
  }
  res = S.Get();
  return res;
}
