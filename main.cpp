#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int s[5]{1, 2, 3};

  try {
    cout << "At index 12: " << s[12] << "\n";
    cout << "No exception thrown." << "\n";
  } catch (exception &e) {
    cout << "\nException caught: " << e.what() << endl;
  }

  return 0;
}