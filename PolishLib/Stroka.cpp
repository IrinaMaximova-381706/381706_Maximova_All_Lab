#include "Stroka.h"

TString::TString()
{
	s = 0;
	length = 0;
}// ---------------------------------------------------------------------------

TString::TString(TString &A)
{
	length = A.length;
	if (length != 0)
	{
		s = new char[length];
		for (int i = 0; i < length; i++)
			s[i] = A.s[i];
	}
	else
		s = 0;
}// ---------------------------------------------------------------------------

TString::TString(char* a) 
{
  if (a == 0)
    throw MyException("error. Empty string.");
  if (a[0] == '\0')
    return;
  char x = 1;
  int size = 0;
  while (x != '\0')
  {
    size++;
    x = a[size];
  }

  length = size + 1; 
  s = new char[length];
  for (int i = 0; i < length - 1; i++)
    s[i] = a[i];
  s[length - 1] = 0;
}// ---------------------------------------------------------------------------

TString::~TString()
{
	if (s != 0)
		delete [] s;
}// ---------------------------------------------------------------------------

int TString::GetLength()
{
	return length;
}// ---------------------------------------------------------------------------

void TString::DeleteS()
{
	if (s != 0)
		delete [] s;
}// ---------------------------------------------------------------------------

TString TString::operator+(TString &A)
{
	TString B;
	B.length = length + A.length - 1; //В обоих массивах на конце стоит 0. Один 0 - лишний
	B.s = new char[B.length];
	for (int i = 0; i < length - 1; i++)
		B.s[i] = s[i];
	for (int i = length - 1; i < B.length; i++)
		B.s[i] = A.s[i - (length - 1)];
	return B;
}// ---------------------------------------------------------------------------

TString& TString::operator=(TString &A)
{
	if (this != &A)
	{
		length = A.length;
		if (length != 0)
		{
			if (s != 0)
				delete[]s;
			s = new char[A.length];
			for (int i = 0; i < A.length; i++)
				s[i] = A.s[i];
		}
		else
		{
			if (s != 0)
				delete[]s;
			s = 0;
		}
	}
	return *this;
}// ---------------------------------------------------------------------------

char& TString::operator[](int i)
{
  if ((i >= 0) && (i < length))
    return s[i];
  throw MyException("error. False index.");
}// ---------------------------------------------------------------------------

std::istream& operator>>(std::istream &A, TString &B)
{
	char s[256] = {0};
	A >> s;

  char x = 1;
  int size = 0;
  while (x != '\0')
  {
    size++;
    x = s[size];
  }

	B.length = size + 1;
	B.s = new char[B.length];
	for (int i = 0; i < B.length - 1; i++)
		B.s[i] = s[i];
	B.s[B.length - 1] = 0;
	return A;
}// ---------------------------------------------------------------------------

std::ostream& operator<<(std::ostream &A, const TString &B)
{
	A << B.s;
	return A;
}// ---------------------------------------------------------------------------