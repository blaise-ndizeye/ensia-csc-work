#include <iostream>
using namespace std;

int main() {
  int num = 0;

  do {
    cout << "Enter a number between 1 and 10" << endl;
    // * When a something like "four" is entered instead of a number, it'll
    // * cause an infinite loop
    cin >> num;
    if (num < 1 || num > 10) {
      cout << "Illegal value " << num << " entered. Try again." << endl;
    }
  } while (num < 1 || num > 10);

  cout << "Value " << num << " correctly entered! Thank you." << endl;
  return 0;
}