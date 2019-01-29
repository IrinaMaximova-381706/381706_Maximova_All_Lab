#include "Polish.h"

int  main()
{
  string s = "((33-22)*33-10)";
  cout << s << " ~ ";
  TQueue<char> B(ConvertToPol(s));
  B.Print();
  cout << " = " << Rez(B) << endl;
  return 0;
}