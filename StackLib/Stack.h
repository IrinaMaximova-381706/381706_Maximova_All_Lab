#pragma once
#include <iostream>
#include <locale.h>
#include "ExceptionLib.h"
using namespace std;

template <class T>
class TStack
{
protected:
  int size; // Ðàçìåð ñòåêà
  int top;  // èíäåêñ âåðøèíû ñòåêà
  T* mas;   // Óêàçàòåëü íà îáëàñòü ïàìÿòè äëÿ õðàíåíèÿ ñòåêà
public:
  TStack(int n = 0);             // êîíñòðóêòîð èíèöèàëèçàöèè
  TStack(TStack<T> &S);          // êîíñòðóêòîð êîïèðîâàíèÿ
  virtual ~TStack();             // äåñòðóêòîð
  int GetSize();                 // ðàçìåð
  T Get();                       // âîçâðàùàåò ýëåìåíò, ðàñïîëîæåííûé íà âåðøèíå ñòåêà
  void Put(T A);                 // ïîëîæèòü ýëåìåíò
  bool IsFull();                 // ïðîâåðêà íà ïîëíîòó
  bool IsEmpty();                // ïðîâåðêà íà ïóñòîòó
  void PrintStack();             // âûâîä ñòåêà íà ýêðàí
  T Top(); 

  int operator!=(const TStack<T>& stack) const; // ïðîâåðêà íà íåðàâåíñòâî
  int operator==(const TStack<T>& stack) const; //ïðîâåðêà íà ðàâåíñòâî
  TStack& operator=(const TStack<T>& stack); // ïðèðàâíèâàíèå
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
    for(int i = 0; i < size; i++)
      mas[i] = 0;
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
}//-------------------------------------------------------------------------

template<class T>
T TStack<T>::Top()
{
  if (IsEmpty())
    throw "Empty";
  else 
  {
    return mas[top - 1];
  }
}//-------------------------------------------------------------------------

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
}//-------------------------------------------------------------------------
