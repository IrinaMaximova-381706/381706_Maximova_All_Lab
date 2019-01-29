#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyException 
{
private:
  string str;
public:
  MyException(string _str) : str(_str) {}
  void Print() { cout << "\nWarning! \nMessage: " << str << endl; }
};
