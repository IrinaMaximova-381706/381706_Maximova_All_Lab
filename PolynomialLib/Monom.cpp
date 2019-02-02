#include "Monom.h"

TMonom::TMonom()
{
  next = NULL;
  power = NULL;
  coeff = 0;
  n = 0;
}// ---------------------------------------------------------------------------

TMonom::TMonom(int _n, int* _power, double _c)
{
  if (_n < 0)
    throw MyException("Negative size");
  else if (_n == 0)
  {
    power = NULL;
    n = _n;
    coeff = _c;
    next = NULL;
  }
  else
  {
    n = _n;
    coeff = _c;
    next = NULL;
    power = new int[_n];
    for (int i = 0; i < _n; i++)
    {
      if (_power[i] >= 0)
        power[i] = _power[i];
      else
        throw MyException("Negative power");
    }
  }
}// ---------------------------------------------------------------------------

TMonom::TMonom(const TMonom &A)
{
  n = A.n;
  coeff = A.coeff;
  next = A.next;
  power = new int[n];
  for (int i = 0; i < n; i++)
  {
    power[i] = A.power[i];
  }
}// ---------------------------------------------------------------------------

TMonom::~TMonom()
{
  if (power != 0)
    delete[]power;
  n = 0;
  coeff = 0;
  next = 0;
}// ---------------------------------------------------------------------------

TMonom* TMonom::GetNext()
{
  return next;
}// ---------------------------------------------------------------------------

int* TMonom::GetPower()
{
  return power;
}// ---------------------------------------------------------------------------

double TMonom::GetC()
{
  return coeff;
}// ---------------------------------------------------------------------------

int TMonom::GetN()
{
  return n;
}// ---------------------------------------------------------------------------

void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}// ---------------------------------------------------------------------------

void TMonom::SetPower(int* _power)
{
  for (int i = 0; i < n; i++)
  {
    if (_power[i] >= 0)
      power[i] = _power[i];
    else
      throw MyException("Negative power");
  }
}// ---------------------------------------------------------------------------

void TMonom::SetC(double _c)
{
  coeff = _c;
}// ---------------------------------------------------------------------------

void TMonom::SetN(int _n)
{
  if (_n < 0)
    throw MyException("Negative size");
  else if (_n == 0)
  {
    if (power != 0)
      delete[] power;
    power = 0;
    n = 0;
  }
  else
  {
    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
      tmp[i] = power[i];
    delete[]power;
    power = new int[_n];
    int i = 0;
    if (n < _n)
    {
      for (; i < n; i++)
        power[i] = tmp[i];
      for (; i < _n; i++)
        power[i] = 0;
    }
    if (_n < n)
      for (; i < _n; i++)
        power[i] = tmp[i];
    n = _n;
  }
}// ---------------------------------------------------------------------------

TMonom& TMonom::operator=(const TMonom& A)
{
  if (n != A.n)
    throw MyException("Error size eq");
  coeff = A.coeff;
  n = A.n;
  next = A.next;
  delete[] power;
  power = new int[n];
  for (int i = 0; i < n; i++)
    power[i] = A.power[i];
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator+(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  tmp.coeff = coeff + A.coeff;
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator+=(TMonom & A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  coeff += A.coeff;
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator-(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  tmp.coeff = coeff - A.coeff;
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator-=(TMonom & A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  coeff -= A.coeff;
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator*(const TMonom& A) const
{
  if (n != A.n)
    throw MyException("Different n");
  TMonom tmp(A);
  tmp.coeff = coeff * A.coeff;
  for (int i = 0; i < n; i++)
    tmp.power[i] = power[i] + A.power[i];
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator*=(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  coeff = coeff * A.coeff;
  for (int i = 0; i < n; i++)
    power[i] += A.power[i];
  return *this;
}// ---------------------------------------------------------------------------

bool TMonom::operator==(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different size");
  for (int i = 0; i < n; i++)
    if (power[i] != A.power[i])
      return false;
  return true;
}// ---------------------------------------------------------------------------

bool TMonom::operator>(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (*this == A)
    throw MyException("Monoms eq");
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] > A.power[i])
      return true;
    else
      return false;
  }
  return true;
}// ---------------------------------------------------------------------------

bool TMonom::operator<(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (*this == A)
    throw MyException("Monoms eq");
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] < A.power[i])
      return true;
    else
      return false;
  }
  if (coeff > A.coeff)
    return false;
  return true;
}// ---------------------------------------------------------------------------

istream& operator>>(istream& istr, TMonom& A)
{
  istr >> A.coeff;
  for (int i = 0; i < A.n; i++)
    istr >> A.power[i];
  return istr;
}// ---------------------------------------------------------------------------

ostream& operator<<(ostream& ostr, TMonom& A)
{
  ostr << A.coeff;
  if (A.coeff != 0)
  {
    for (int i = 0; i < A.n; i++)
      if (A.power[i] != 0)
      {
        ostr << "*x" << i;
        if (A.power[i] != 1)
          ostr << "^" << A.power[i];
      }
  }
  return ostr;
}// ---------------------------------------------------------------------------
