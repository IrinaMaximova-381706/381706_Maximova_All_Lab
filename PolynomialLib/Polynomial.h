#pragma once
#include "Monom.h"

class TPolynom
{
protected:
  TMonom *start;
  int n;          //количество переменных в мономе
  int size;       //количество мономов 
public:
  TPolynom(int _n = 3);
  TPolynom(TPolynom &p);
  ~TPolynom();
  int GetSize();
  TMonom* GetStart();
  TPolynom operator-(TPolynom &p);
  TPolynom operator+(TPolynom &p);
  TPolynom& operator=(const TPolynom &p);
  bool operator==(const TPolynom &p);
  TPolynom operator*(TPolynom &p);
  TPolynom& operator+=(TMonom &m);
  TPolynom& operator-=(TMonom &m);
  friend std::ostream& operator<<(std::ostream& _s, TPolynom& Tm);
};

