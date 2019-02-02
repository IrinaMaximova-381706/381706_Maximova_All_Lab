#include "Polynomial.h"

int main() 
{
  int ms1[] = { 1, 2, 3 };
  int ms2[] = { 4, 5, 6 };
  int ms3[] = { 0, 8, 9 };
  int ms4[] = { 1, 9, 3 };
  int ms5[] = { 2, 6, 0 };
  int ms6[] = { 1, 2, 3 };

  try
  {
    TMonom A(3, ms1, 1);
    TMonom B(3, ms2, 2);
    TMonom C(3, ms3, 0);
    TMonom D(3, ms4, 4);
    TMonom E(3, ms5, 5);
    TMonom F(3, ms6, 6);

    cout << "Monom A: " << A << endl;
    cout << "Monom B: " << B << endl;
    cout << "Monom C: " << C << endl;
    cout << "Monom D: " << D << endl;
    cout << "Monom E: " << E << endl;
    cout << "Monom F: " << F << endl;


    TPolynom p_one(3);
    p_one += A;
    p_one += B;
    p_one += C;
    cout << "\nPolynom one = A + B + C = " << p_one << endl;

    TPolynom p_two(3);
    p_two += D;
    p_two += E;
    p_two += F;
    cout << "Polynom two = D + E + F = " << p_two << endl;

    TPolynom pol(3);
    TPolynom polk(3);

    pol = p_one + p_two;
    cout << "\nPolynom one + two = " << pol << endl;

    pol = p_one - p_two;
    cout << "Polynom one - two = " << pol << endl;

    pol = p_one * p_two;
    cout << "Polynom one * two = " << pol << endl;
  }

  catch (MyException exp)
  {
    exp.Print();
  }


 return 0;
}
