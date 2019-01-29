#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
class TNewStack : public TStack<T>
{
public:
  TNewStack(int _size, T* _mas);
  TNewStack(TNewStack<T>& A);
  int GetFreeMem();
  T Get();
  void Push(T _A);
  int GetSize();
  int GetTop();
  void SetMas(int _size, T* _mas);
  void PrintNewStack();       
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
  if (_size <= 0)
    throw MyException("Negative size");
  top = 0;
  size = _size;
  mas = _mas;
}//-------------------------------------------------------------------------

template <class T>
TNewStack<T>::TNewStack(TNewStack<T>& A)
{
  top = A.top;
  size = A.size;
  mas = A.mas;
}//-------------------------------------------------------------------------

template <class T>
int TNewStack<T>::GetFreeMem()
{
  return size - top;
}//-------------------------------------------------------------------------

template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas)
{
  if (_size <= 0)
    throw MyException("Negative size");
  size = _size;
  mas = _mas;
}//-------------------------------------------------------------------------

template <class T>
int TNewStack<T>::GetTop()
{
  return top;
}//-------------------------------------------------------------------------

template <class T>
int TNewStack<T>::GetSize()
{
  return size;
}//-------------------------------------------------------------------------

template <class T>
void TNewStack<T>::Push(T _A)
{
  mas[top] = _A;
  top++;
}//-------------------------------------------------------------------------

template <class T>
T TNewStack<T>::Get() 
{
  top--;
  return mas[top];
}//-------------------------------------------------------------------------

template <class T>
void TNewStack<T>::PrintNewStack()
{
  for (int i =  0; i < TStack<T>::top; i++)
    cout << " " << TStack<T>::mas[i];
}//-------------------------------------------------------------------------
