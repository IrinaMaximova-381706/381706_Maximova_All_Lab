#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);
  TMatrix(const TVector<TVector<T> > &mt);
  virtual ~TMatrix();

  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator=(const TMatrix &mt);        // присваивание
  TMatrix operator+(const TMatrix &mt);         // сложение
  TMatrix operator-(const TMatrix &mt);         // вычитание
  TMatrix<T> operator*(const TMatrix<T> &MT);    // умножение
  TMatrix<T> operator/(const TMatrix<T> &MT);    //деление

  template <class ValType2>
  friend istream& operator>>(istream &in, TMatrix<ValType2> &mt);
  template <class ValType2>
  friend ostream & operator<<(ostream &out, const TMatrix<ValType2> &mt);
};

template <class T>
TMatrix<T>::TMatrix(int s) :TVector<TVector<T> >(s)
{
  if (s <= 0 || s > 1000)
    throw MyException("error size");
  for (int i = 0; i < s; i++)
    this->vec[i] = TVector<T>(s - i);
} //-------------------------------------------------------------------------

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &mt) :TVector<TVector<T> >(mt)
{}//-------------------------------------------------------------------------

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt) : TVector<TVector<T> >(mt)
{}//-------------------------------------------------------------------------

template <class T>
TMatrix<T>::~TMatrix()
{}//-------------------------------------------------------------------------

template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
  return TVector<TVector<T> >::operator==(mt);
} //-------------------------------------------------------------------------

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
  return TVector<TVector<T> >::operator!=(mt);
} //-------------------------------------------------------------------------

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
  TVector<TVector<T> >::operator=(mt);
  return *this;
} //-------------------------------------------------------------------------

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
  if (this->size == mt.size)
    return TVector<TVector<T> >::operator+(mt);
  else
    throw MyException("error size operand");
} //-------------------------------------------------------------------------

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
  if (this->size == mt.size)
    return TVector<TVector<T> >::operator-(mt);
  else
    throw MyException("error size operand");
} //-------------------------------------------------------------------------

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw MyException("error size operand");
  TMatrix <T> rez(this->size);
  for (int i = 0; i < this->size; i++)
    for (int j = i; j < this->size; j++)
    {
      for (int k = i; k <= j; k++)
        rez.vec[i][j - i] += this->vec[i][k - i] * mt.vec[k][j - k];
    }
  return rez;
}//-------------------------------------------------------------------------

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw MyException("error size operand");
  TMatrix <T> copy(*this);
  TMatrix <T> rez(this->size);
  TMatrix <T> copyMt(mt);

  for (int i = 0; i < this->size; i++)
    rez[i][0] = 1 / copyMt[i][0];

  for (int i = 0; i < this->size - 1; i++)
    for (int j = 1; j < this->size - i; j++)
    {
      if (copyMt[i][j] != 0)
      {
        T temp = copyMt[i][j];
        rez[i][j] = (-1) * copyMt[i][j] * rez[i + j][0];
        for (int k = j, l = 0; k < this->size - i; k++)
          copyMt[i][k] = copyMt[i][k] - copyMt[j][l++] * temp;
      }
    }
  rez = copy * rez;
  return rez;
}//-------------------------------------------------------------------------


template <class ValType2>
istream& operator>>(istream &in, TMatrix<ValType2> &mt)
{
  for (int i = 0; i < mt.size; i++)
    in >> mt.vec[i];
  return in;
}//-------------------------------------------------------------------------

template <class ValType2>
ostream & operator<<(ostream &out, const TMatrix<ValType2> &mt)
{
  for (int i = 0; i < mt.size; i++)
  {
    for (int k = 0; k < i; k++)
      out << "  ";
    out << mt.vec[i] << endl;
  }
  return out;
}