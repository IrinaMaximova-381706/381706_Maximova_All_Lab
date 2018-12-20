#pragma once

template <class T>
class TElem
{
protected:
  T data;                                   //значение которуе хранит элемент
  TElem <T>* next;                          //указатель на следующий элемент
public:
  TElem(T _data = 0, TElem <T>* _next = 0); //конструктор по умолчанию
  TElem(TElem<T> &E);                       //конструктор копирования
  virtual ~TElem();                         //деструктор

  TElem* GetNext();                         //получить адрес следующего элемента
  T GetData();                              //получить значение элемента
  void Set(T e);                            //положить значение элемента
  void SetNext(TElem <T>* n);               //указать адрес следующего элемента
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next)
{
  data = _data;
  next = _next;
}//-------------------------------------------------------------------------

template <class T>
TElem<T>::TElem(TElem<T> &E)
{
  data = E.data;
  next = E.next;
}//-------------------------------------------------------------------------

template <class T>
TElem<T>::~TElem() {}

template <class T>
T TElem<T>::GetData()
{
  return data;
}//-------------------------------------------------------------------------

template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}//-------------------------------------------------------------------------

template <class T>
void TElem<T>::Set(T _e)
{
  data = _e;
}//-------------------------------------------------------------------------

template <class T>
void TElem<T>::SetNext(TElem<T>* _n)
{
  next = _n;
}//-------------------------------------------------------------------------