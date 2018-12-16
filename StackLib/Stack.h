#pragma once
#include <iostream>
#include <locale.h>
#include "ExceptionLib.h"
using namespace std;

template <class T>
class TStack
{
protected:
  int size; // Размер стека
  int top;  // индекс вершины стека
  T* mas;   // Указатель на область памяти для хранения стека
public:
  TStack(int n = 0);             // конструктор инициализации
  TStack(TStack<T> &S);          // конструктор копирования
  virtual ~TStack();             // деструктор
  int GetSize();                 // размер
  T Get();                       // возвращает элемент, расположенный на вершине стека
  void Put(T A);                 // положить элемент
  bool IsFull();                 // проверка на полноту
  bool IsEmpty();                // проверка на пустоту
  void PrintStack();             // вывод стека на экран

  int operator!=(const TStack<T>& stack) const; // проверка на неравенство
  int operator==(const TStack<T>& stack) const; //проверка на равенство
  TStack& operator=(const TStack<T>& stack); // приравнивание
};

template <class T>
TStack<T>::TStack(int n)
{
  if (n < 0)
    throw MyException("error size stack");
  if (n == 0)
  {
    size = 0;
    top = 0;
    mas = NULL;
  }
  else
  {
    size = n;
    top = 0;
    mas = new T[size];
    memset(mas, size, 0);
  }
}//-------------------------------------------------------------------------

template <class T>
TStack<T>::TStack(TStack<T>& s)
{
  size = s.size;
  top = s.top;
  if (size == 0)
    mas = NULL;
  else
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = s.mas[i];
  }
}//-------------------------------------------------------------------------

template<class T>
TStack <T>::~TStack()
{
  top = size = 0;
  delete[] mas;
}//-------------------------------------------------------------------------

template <class T>
int TStack<T>::GetSize()
{
  return size;
}//-------------------------------------------------------------------------

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw MyException("error Get(). Stack is empty!");
  top--;
  return mas[top];
}//-------------------------------------------------------------------------

template <class T>
void TStack<T>::Put(T a)
{
  if (IsFull())
    throw MyException("error Put(). Stack in full!");
  else
  {
    mas[top] = a;
    top++;
  }
}//-------------------------------------------------------------------------

template <class T>
bool TStack<T>::IsFull()
{
  if (top >= size)
    return 1;
  return 0;
}//-------------------------------------------------------------------------

template <class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
    return 1;
  return 0;
}//-------------------------------------------------------------------------

template <class T>
void TStack<T>::PrintStack()
{

  for (int i = top - 1; i >= 0; i--)
    cout << " " << mas[i];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
  if (this != &s)
  {
    delete[] mas;
    top = s.top;
    size = s.size;
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = s.mas[i];
  }
  return *this;
}//----------------------------------------------------------------------

template <class T>
int TStack<T>::operator==(const TStack<T>& s) const
{
  if (top != s.top)
    return 0;
  if (size != s.size)
    return 0;
  for (int i = 0; i < top; i++)
    if (mas[i] != s.mas[i])
      return 0;
  return 1;
}//----------------------------------------------------------------------

template <class T>
int TStack<T>::operator!=(const TStack<T>& s) const
{
  return !(*this == s);
}