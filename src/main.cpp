#include "../lib/exceptions.h"
#include <iostream>
#include <math.h>
using namespace std;

void separator() { cout << "\n____________________\n\n"; }

int main(int argc, char const *argv[]) {
  int num1, num2;

  try {
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    if (num2 == 0)
      throw DivideByZeroException();

    cout << num1 << " ÷ " << num2 << " = " << (static_cast<double>(num1) / num2)
         << "\n";

    separator();
    cin.clear();

    cout << "Enter a large number: ";
    cin >> num1;

    if (num1 > 5000000)
      throw OverFlowException();

    cout << "\n" << num1 << " is not that large 😒 \n";

    separator();
    cin.clear();

    cout << "Enter the number to find it's square root: ";
    cin >> num1;

    if (num1 < 0)
      throw RootOfNegativeException();

    cout << "Sqrt(" << num1 << ") = " << sqrt(num1) << "\n";
  } catch (const MathException &e) {
    cerr << e.what() << '\n';
  }

  cout << "\n";
  return 0;
}
