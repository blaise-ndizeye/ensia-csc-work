#include "../lib/double_scripted_array.h"
#include <iostream>
using namespace std;

int main() {
  DoubleScriptedArray<string> words(3, 3);
  DoubleScriptedArray<int> integers1(2, 3);

  cout << "\nUninitialized 1st DoubleScriptedArray<int>: \n";
  cout << integers1;

  cout << "Initialize 1st DoubleScriptedArray<int>: \n";
  cin >> integers1;

  cout << "\nInitialized 1st DoubleScriptedArray<int>: \n";
  cout << integers1;

  cout << "Initialize DoubleScriptedArray<string>: \n";
  cin >> words;

  cout << "\nInitialized DoubleScriptedArray<string>: \n";
  cout << words;

  cout << "\nCreate and initialize 2nd DoubleScriptedArray<int>: \n";
  DoubleScriptedArray<int> integers2(3, 2);
  cin >> integers2;

  cout << "Initialized 2nd DoubleScriptedArray<int>: \n";
  cout << integers2;

  cout << "Assign 'Hello' at 2×1 in DoubleScriptedArray<string>: \n";
  words(2, 1) = "Hello";
  cout << words;

  cout << "\nAssign first to second integers1 = integers2: \n";
  integers1 = integers2;

  cout << "\n1st DoubleScriptedArray<int>: \n";
  cout << integers1;

  cout << "2nd DoubleScriptedArray<int>: \n";
  cout << integers2;

  cout << "\n";
  return 0;
}