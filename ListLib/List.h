#pragma once 
#include "Elem.h"
#include "ExceptionLib.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* begin;    //указатель на элемент в начале списака
public:
  TList();            //конструктор по умолчанию
  TList(TList<T> &L); //конструктор копирования
  virtual ~TList();   //деструктор

  void PutBegin(T A); //положмть в начало 
  void PutEnd(T A);   //положить в конец 
  T GetBegin();       //получить элемент в начале списка 
  T GetEnd();         //получить элемент в конце списка 
  bool IsFull();      //проверка на полноту 
  bool IsEmpty();     //проверка на пустоту 
  void Print();       //печать листа 
};

template <class T>
TList<T>::TList()
{
  begin = 0;
}//-------------------------------------------------------------------------

template <class T>
TList<T>::TList(TList<T> &L)
{
  TElem<T>* a = L.begin;
  TElem<T>* b;
  if (L.begin == 0)
    begin = 0;
  else
  {
    begin = new TElem<T>(*L.begin);
    b = begin;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TElem<T>(*(a->GetNext())));
      a = a->GetNext();
      b = b->GetNext();
    }
  }
}//-------------------------------------------------------------------------

template <class T>
TList<T>::~TList()
{
  while (begin != 0)
  {
    TElem<T>* temp = begin;
    begin = begin->GetNext();
    delete temp;
  }
}//-------------------------------------------------------------------------

template <class T>
void TList<T>::PutBegin(T A)
{
  if (begin == 0)
  {
    TElem<T>* temp = new TElem<T>(A, 0);
    begin = temp;
  }
  else
  {
    TElem<T>* temp = new TElem <T>(A, begin);
    begin = temp;
  }
}//-------------------------------------------------------------------------

template <class T>
void TList<T>::PutEnd(T A)
{
  if (begin != 0)
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElem <T>(A, 0));
  }
  else
    begin = new TElem<T>(A, 0);
}//-------------------------------------------------------------------------

template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw MyException("error. List is empty!");
  else {
    TElem<T>* a = begin;
    T temp = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    delete a;
    return temp;
  }
}//-------------------------------------------------------------------------

template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw MyException("error. List is Empty!");
  else
  {
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    if (b == 0)
    {
      T temp = a->TElem<T>::GetData();
      delete a;
      begin = 0;
      return temp;
    }
    else
    {
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetData();
      delete b;
      a->SetNext(0);
      return temp;
    }
  }
  }//-------------------------------------------------------------------------

  template <class T>
  bool TList<T>::IsFull()
  {
    try
    {
      TElem<T>* a = new TElem<T>();
      if (a == NULL)
        return 0;
      else
      {
        delete a;
        return 1;
      }
    }
    catch (...)
    {
      return 0;
    }
  }//-------------------------------------------------------------------------

  template <class T>
  bool TList<T>::IsEmpty()
  {
    if (begin == 0)
      return 1;
    return 0;
  }//-------------------------------------------------------------------------

  template<class T>
  inline void TList<T>::Print()
  {
    if (begin == 0)
      throw MyException("Error! List is Empty.");
    else
    {
      TElem<T>* a = begin;
      while (a->GetNext() != 0)
      {
        cout << a->GetData() << " ";
        a = a->GetNext();
      }
      cout << a->GetData() << " ";
    }

  }//-------------------------------------------------------------------------