#pragma once
#include <iostream>
using namespace std;

template <class T>
class TVector
{
protected:
  T *vec;     
  int size;   
public:
  TVector(int s = 0);
  TVector(const TVector &v);                
  virtual ~TVector();

  int GetSize() const; 
  virtual T& operator[](int pos);         
  bool operator==(const TVector &v) const;  // ñðàâíåíèå
  bool operator!=(const TVector &v) const;  // ñðàâíåíèå
  virtual TVector& operator=(const TVector &v); // ïðèñâàèâàíèå

  TVector operator+(const T &val);   // ïðèáàâèòü ñêàëÿð
  TVector operator-(const T &val);   // âû÷åñòü ñêàëÿð
  TVector operator*(const T &val);   // óìíîæèòü íà ñêàëÿð

  TVector operator+(const TVector &v);     // ñëîæåíèå
  TVector operator-(const TVector &v);     // âû÷èòàíèå
  T operator*(const TVector &v);     // ñêàëÿðíîå ïðîèçâåäåíèå

  template <class ValType1>
  friend istream& operator>>(istream &in, TVector<ValType1>& v);
  template <class ValType1>
  friend ostream& operator<<(ostream &out, const TVector<ValType1>& v);
}; 

template <class T>
TVector<T>::TVector(int s)
{
	if (s < 0)
		throw 1;
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
		throw 1;
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
    throw 1;
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] + v.vec[i];
  return rez;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
  if (size != v.size)
    throw 1;
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] - v.vec[i];
  return rez;
} //-------------------------------------------------------------------------

template <class T> 
T TVector<T>::operator*(const TVector<T> &v)
{
  if (size != v.size)
    throw 1;
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

