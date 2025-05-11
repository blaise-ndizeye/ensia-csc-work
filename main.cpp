#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Hello";

  try {
    cout << "At index 12: " << s.at(12) << "\n";
    cout << "No exception thrown." << "\n";
  } catch (exception &e) {
    cout << "\nException caught: " << e.what() << endl;
  }

  return 0;
}