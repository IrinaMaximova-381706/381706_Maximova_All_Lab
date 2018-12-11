#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyException 
{
private:
  string str;
public:
  MyException(std::string _str);
  void Print();
};

MyException::MyException(std::string _str) : str(_str) {}

void MyException::Print()
{
  cout << "\nWarning! \nMessage: " << str << endl;
}
