#pragma once
#include "ExceptionLib.h"

template <class T>
class TVector
{
protected:
  T *vec;     //указатель на вектор 
  int size;       // размер вектора
public:
  TVector(int s = 0);
  TVector(const TVector &v);                
  virtual ~TVector();

  int GetSize() const; // размер вектора
  virtual T& operator[](int pos);           // доступ
  
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  virtual TVector& operator=(const TVector &v); // присваивание

  TVector operator+(const T &val);   // прибавить скаляр
  TVector operator-(const T &val);   // вычесть скаляр
  TVector operator*(const T &val);   // умножить на скаляр

  TVector operator+(const TVector &v);     // сложение
  TVector operator-(const TVector &v);     // вычитание
  T operator*(const TVector &v);     // скалярное произведение

  template <class ValType1>
  friend istream& operator>>(istream &in, TVector<ValType1>& v);
  template <class ValType1>
  friend ostream& operator<<(ostream &out, const TVector<ValType1>& v);
}; 

template <class T>
TVector<T>::TVector(int s)
{
	if (s < 0)
		throw MyException("error size");
  else
    if (s == 0) 
    {
      size = s;
      vec = NULL;
    }
    else 
    {
      size = s;
      vec = new T[size];
      for (int i = 0; i < size; i++)
        vec[i] = 0;
    }
} //-------------------------------------------------------------------------

template <class T> 
TVector<T>::TVector(const TVector<T> &V) 
{
  size = V.size;
  if (size == 0)
    vec = NULL;
  else 
  {
    vec = new T[size];
    for (int i = 0; i < size; i++)
      vec[i] = V.vec[i];
  }
} //-------------------------------------------------------------------------

template<class T>
TVector<T>::~TVector() 
{
  if (size > 0)
  {
    size = 0;
    delete[] vec;
    vec = NULL;
  }
} //-------------------------------------------------------------------------

template <class T>
int TVector<T>::GetSize() const
{ 
  return size; 
}//-------------------------------------------------------------------------

template <class T> 
T& TVector<T>::operator[](int pos)
{
	if (pos >= 0 && pos < size)
		return vec[pos];
	else
		throw MyException("error index");
} //-------------------------------------------------------------------------

template <class T>
bool TVector<T>::operator==(const TVector &v) const
{
	if (size != v.size)
		return 0;
	else
		for (int i = 0; i < size; i++)
			if (vec[i] != v.vec[i])
			{
        return 0;
			}
	return 1;
} //-------------------------------------------------------------------------

template <class T> 
bool TVector<T>::operator!=(const TVector &v) const
{
  return !(*this == v);
} //-------------------------------------------------------------------------

template <class T> 
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this != &v)
	{
		delete[] vec;
		size = v.size;
		vec = new T[size];
		for (int i = 0; i < size; i++)
			vec[i] = v.vec[i];
	}
	return *this;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.vec[i] += val;
	return res;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator-(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.vec[i] -= val;
	return res;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator*(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.vec[i] = res.vec[i] * val;
	return res;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("error size operand");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] + v.vec[i];
  return rez;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("error size operand");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] - v.vec[i];
  return rez;
} //-------------------------------------------------------------------------

template <class T> 
T TVector<T>::operator*(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("error size operand");
  int temp = 0;
  for (int i = 0; i < size; i++)
    temp += vec[i] * v.vec[i];
  return temp;
} //-------------------------------------------------------------------------

template <class T>
istream& operator>>(istream &in, TVector<T> &v)
{
	for (int i = 0; i < v.size; i++)
		in >> v.vec[i];
	return in;
}//-------------------------------------------------------------------------

template <class T>
ostream& operator<<(ostream &out, const TVector<T> &v)
{
	for (int i = 0; i < v.size; i++)
		out << v.vec[i] << ' ';
	return out;
}

