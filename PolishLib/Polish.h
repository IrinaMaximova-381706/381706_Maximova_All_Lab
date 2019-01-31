#pragma once
#include "Queue.h"
#include "Stroka.h"

int GetPrt(const char op);
bool IsOp(char a);
TQueue<char> ConvertToPol(TString s);
double Rez(TQueue<char> q);
