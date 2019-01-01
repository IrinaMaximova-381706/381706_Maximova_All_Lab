#pragma once

template <class T>
class TElem
{
protected:
  T data;
  TElem<T>* next;
public:
  TElem<T>(T _data = 0, TElem<T>* n = 0);
  TElem<T>(TElem<T>& A);
  T GetData();
  TElem<T>* GetNext();
  void SetData(T _data);
  void SetNext(TElem<T>* n);
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* n)
{
  data = _data;
  next = n;
}//-------------------------------------------------------------------------------------------------

template <class T>
TElem<T>::TElem(TElem<T>& A)
{
  data = A.data;
  next = A.next;
}//-------------------------------------------------------------------------------------------------

template <class T>
T TElem<T>::GetData()
{
  return data;
}//-------------------------------------------------------------------------------------------------

template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}//-------------------------------------------------------------------------------------------------

template <class T>
void TElem<T>::SetData(T _data)
{
  data = _data;
}//-------------------------------------------------------------------------------------------------

template <class T>
void TElem<T>::SetNext(TElem<T>* n)
{
  next = n;
}//-------------------------------------------------------------------------------------------------