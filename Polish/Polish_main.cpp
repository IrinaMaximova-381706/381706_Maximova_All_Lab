#include "Polish.h"

int  main()
{
  try
  {
    cout << "Enter your math expression: ";
    TString s;
    cin >> s;
    cout << s << " ~ ";
    TQueue<char> B;
    B = ConvertToPol(s);
    B.Print();
    cout << " = " << Rez(B) << endl;
  }
  
  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}
