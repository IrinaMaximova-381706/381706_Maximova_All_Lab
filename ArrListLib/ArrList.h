#pragma once
#include "ExceptionLib.h"
#include "Queue.h"

template <class T>
class TArrList
{
private:
  T* mas;                    //Массив элементов списка
  int *nextInd;              //Массив индексов, указывающих на следюущий элемент списка
  int *predInd;              //Массив индексов, указывающих на предыдущий элемент списка
  int size;                  //Размер списка
  int count;                 //Количество элементов в списке
  int start;                 //Индекс первого элемента списка
  int end;                   //Индекс последнего элемента списка
  TQueue <int> freeElem;     //Очередь "пустых" ячеек в массиве,  
public:
  TArrList(int _size = 10);  //Конструктор с параметром
  TArrList(TArrList<T> &A);  //Конструктор копирования
  ~TArrList();               //Деструктор
  void Put(int n, T elem);   //Добавить промежуточный элемент
  T Get(int n);              //Извлечь промежутьчный элемент 
  void PutStart(T elem);     //Положить в начало списка
  void PutEnd(T elem);       //Положить в конец списка 
  T GetStart();              //Забрать из начала списка с удалением
  T GetEnd();                //Забрать из конца списка с удалением
  bool IsFull();             //Проверка на полноту
  bool IsEmpty();            //Проверка на пустоту
  void Print();              //Печать списка
};

template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw MyException("error. False size list");
  size = _size;
  count = 0;
  start = -1;
  end = -1;
  mas = new T[size];
  nextInd = new int[size];
  predInd = new int[size];
  for (int i = 0; i < size; i++)
  {
    nextInd[i] = -2;
    predInd[i] = -2;
    freeElem.Put(i);
  }
}//-----------------------------------------------------------------

template <class T>
TArrList<T>::TArrList(TArrList<T> &A)
{
  start = A.start;
  end = A.end;
  size = A.size;
  count = A.count;
  mas = new T[size];
  nextInd = new int[size];
  predInd = new int[size];
  freeElem = A.freeElem;
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    nextInd[i] = A.nextInd[i];
    predInd[i] = A.predInd[i];
  }
}//-----------------------------------------------------------------

template<class T>
inline TArrList<T>::~TArrList()
{
  delete[] mas;
  delete[] nextInd;
  delete[] predInd;
}//-----------------------------------------------------------------

template<class T>
void TArrList<T>::Put(int n, T elem)
{
  if (IsFull())
    throw MyException("error. List is full");
  if (n < 1 || n > count - 1)
    throw MyException("error. Uncurrent index");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  int one = start;
  int two = nextInd[start];
  for (int i = 0; i < n - 1; i++)
  {
    one = two;
    two = nextInd[two];
  }
  nextInd[ifree] = two;
  nextInd[one] = ifree;

  predInd[ifree] = one;
  predInd[two] = ifree;
  count++;
}//-----------------------------------------------------------------

template<class T>
T TArrList<T>::Get(int n)
{
  if (IsEmpty())
    throw MyException("error. List is empty");
  if (n < 1 || n > count - 1)
    throw MyException("error. Uncurrent index");
  int ind = start;
  for (int i = 0; i < n; i++)
    ind = nextInd[ind];
  nextInd[predInd[ind]] = nextInd[ind];
  predInd[nextInd[ind]] = predInd[ind];
  T temp = mas[ind];
  freeElem.Put(ind);
  count--;
  return temp;
}//-----------------------------------------------------------------

template <class T>
void TArrList<T>::PutStart(T elem)
{
  if (IsFull())
    throw MyException("error. List is full");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  nextInd[ifree] = start;
  if (start != -1)
    predInd[start] = ifree;
  else
    end = ifree;
  start = ifree;
  count++;
}//-----------------------------------------------------------------

template <class T>
void TArrList<T>::PutEnd(T elem)
{
  if (IsFull())
    throw MyException("error. List is full");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  if (end != -1)
    nextInd[end] = ifree;
  else
  {
    start = ifree;
    predInd[ifree] = -1;
  }
  predInd[ifree] = end;
  end = ifree;
  count++;
}//-----------------------------------------------------------------

template <class T>
T TArrList<T>::GetStart()
{
  if (IsEmpty())
    throw MyException("error. List is empty");
  T elem = mas[start];
  freeElem.Put(start);
  int newstart = nextInd[start];
  nextInd[start] = predInd[start] = -2;
  if (newstart != -1)
    predInd[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}//-----------------------------------------------------------------

template <class T>
T TArrList<T>::GetEnd()
{
  if (IsEmpty())
    throw MyException("error. List is empty");
  T elem = mas[end];
  int newFinish = predInd[end];
  predInd[end] = nextInd[end] = -2;
  freeElem.Put(end);
  end = newFinish;
  if (newFinish != -1)
    nextInd[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}//-----------------------------------------------------------------

template <class T>
bool TArrList<T>::IsFull()
{
  if (count == size)
    return true;
  return false;
}//-----------------------------------------------------------------

template <class T>
bool TArrList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  return false;
}//-----------------------------------------------------------------

template<class T>
inline void TArrList<T>::Print()
{
  int it = start;
  for (int i = 0; i < count; i++)
  {
    cout << mas[it] << " ";
    it = nextInd[it];
  }
}//-----------------------------------------------------------------