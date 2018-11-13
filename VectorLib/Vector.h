#pragma once
#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// ������ �������
template <class T>
class TVector
{
protected:
  T *pVector;
  int Size;       // ������ �������
  int StartIndex; // ������ ������� �������� �������
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // ����������� �����������
  ~TVector();
  int GetSize()      { return Size;       } // ������ �������
  int GetStartIndex(){ return StartIndex; } // ������ ������� ��������
  virtual T& operator[](int pos);             // ������
  bool operator==(const TVector &v) const;  // ���������
  bool operator!=(const TVector &v) const;  // ���������
  virtual TVector& operator=(const TVector &v);     // ������������

  // ��������� ��������
  TVector  operator+(const T &val);   // ��������� ������
  TVector  operator-(const T &val);   // ������� ������
  TVector  operator*(const T &val);   // �������� �� ������

  // ��������� ��������
  TVector  operator+(const TVector &v);     // ��������
  TVector  operator-(const TVector &v);     // ���������
  T  operator*(const TVector &v);     // ��������� ������������

  // ����-�����
  template <class ValType1>
  friend istream& operator>>(istream &in, TVector<ValType1>& v);
  template <class ValType1>
  friend ostream& operator<<(ostream &out, const TVector<ValType1>& v);
}; 

template <class T>
TVector<T>::TVector(int s, int si)
{
	if (s<0 || s> MAX_VECTOR_SIZE)
		throw ("error1");
	if (si<0)
		throw ("error1");
	else
	{
		Size = s;
		StartIndex = si;
		pVector = new T[Size];
	}
} //-------------------------------------------------------------------------

template <class T> //����������� �����������
TVector<T>::TVector(const TVector<T> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new T[Size];
	for (int i = 0; i<Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
} //-------------------------------------------------------------------------

template <class T>
TVector<T>::~TVector()
{
	delete[] pVector;
} //-------------------------------------------------------------------------

template <class T> // ������
T& TVector<T>::operator[](int pos)
{
	if (pos >= StartIndex && pos < Size + StartIndex)
		return pVector[pos - StartIndex];
	else
		throw "error";
} //-------------------------------------------------------------------------

template <class T> // ���������
bool TVector<T>::operator==(const TVector &v) const
{
	int res = 1;
	if (Size != v.Size || StartIndex != v.StartIndex)
		res = 0;
	else
		for (int i = 0; i < Size; i++)
			if (pVector[i] != v.pVector[i])
			{
				res = 0;
				break;
			}
	return res;
} //-------------------------------------------------------------------------

template <class T> // ���������
bool TVector<T>::operator!=(const TVector &v) const
{
	int res = 1;
	if (*this == v)
		res = 0;
	return res;
} //-------------------------------------------------------------------------

template <class T> // ������������
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this != &v)
	{
		delete[] pVector;
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new T[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
} //-------------------------------------------------------------------------

template <class T> // ��������� ������
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < Size; i++)
		res.pVector[i] += val;
	return res;
} //-------------------------------------------------------------------------

template <class T> // ������� ������
TVector<T> TVector<T>::operator-(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < Size; i++)
		res.pVector[i] -= val;
	return res;
} //-------------------------------------------------------------------------

template <class T> // �������� �� ������
TVector<T> TVector<T>::operator*(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < Size; i++)
		res.pVector[i] *= val;
	return res;
} //-------------------------------------------------------------------------

template <class T> // ��������
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
	if (Size == v.Size && StartIndex == v.StartIndex)
	{
		TVector<T> res(*this);
		for (int i = 0; i < Size; i++)
			res.pVector[i] = res.pVector[i] + v.pVector[i];
		return res;
	}
	else
		throw "error";
} //-------------------------------------------------------------------------

template <class T> // ���������
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
	if (Size == v.Size && StartIndex == v.StartIndex)
	{
		TVector<T> res(*this);
		for (int i = 0; i < Size; i++)
			res.pVector[i] = res.pVector[i] - v.pVector[i];
		return res;
	}
	else
		throw "error";
} //-------------------------------------------------------------------------

template <class T> // ��������� ������������
T TVector<T>::operator*(const TVector<T> &v)
{
	if (Size == v.Size && StartIndex == v.StartIndex)
	{
		T res = 0;
		for (int i = 0; i < Size; i++)
			res = res + (pVector[i] * v.pVector[i]);
		return res;
	}
	else
		throw "error";
} //-------------------------------------------------------------------------
template <class T>
istream& operator>>(istream &in, TVector<T> &v)
{
	for (int i = 0; i < v.Size; i++)
		in >> v.pVector[i];
	return in;
}
//-------------------------------------------------------------------------
template <class T>
ostream& operator<<(ostream &out, const TVector<T> &v)
{
	for (int i = 0; i < v.Size; i++)
		out << v.pVector[i] << ' ';
	return out;
}

// ����������������� �������
template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // �����������
  TMatrix(const TVector<TVector<T> > &mt); // �������������� ����
  bool operator==(const TMatrix &mt) const;      // ���������
  bool operator!=(const TMatrix &mt) const;      // ���������
  TMatrix& operator= (const TMatrix &mt);        // ������������
  TMatrix  operator+ (const TMatrix &mt);        // ��������
  TMatrix  operator- (const TMatrix &mt);        // ���������

  // ���� / �����
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class T>
TMatrix<T>::TMatrix(int s):TVector<TVector<T> >(s)
{
	if (s >= this->Size && s <= MAX_MATRIX_SIZE)//s<size
	{
		for (int i = 0; i < s; i++)
			this->pVector[i] = TVector<T>(s - i, i);
	}
	else
		throw "Warning";
} //-------------------------------------------------------------------------

template <class T> // ����������� �����������
TMatrix<T>::TMatrix(const TMatrix<T> &mt):TVector<TVector<T> >(mt)
{
	for (int i = 0; i < this->Size; i++)
		this->pVector[i] = mt.pVector[i];
}//-------------------------------------------------------------------------

template <class T> // ����������� �������������� ����
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt):TVector<TVector<T> >(mt) 
{

}//-------------------------------------------------------------------------

template <class T > // ���������
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
	return TVector<TVector<T> >::operator==(mt);
} //-------------------------------------------------------------------------

template <class T> // ���������
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
	return TVector<TVector<T> >::operator!=(mt);
} //-------------------------------------------------------------------------

template <class T> // ������������
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
	TVector<TVector<T> >::operator=(mt);
	return *this;
} //-------------------------------------------------------------------------

template <class T> // ��������
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
	if (this->Size == mt.Size)
		return TVector<TVector<T> >::operator+(mt);
	else
		throw "Warning";
} //-------------------------------------------------------------------------

template <class T> // ���������
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
	if (this->Size == mt.Size)
		return TVector<TVector<T> >::operator-(mt);
	else
		throw "Warning";
} //-------------------------------------------------------------------------


