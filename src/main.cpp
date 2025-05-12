#include "../lib/stack.h"
#include <exception>
#include <iostream>
using namespace std;

void separator() { cout << "\n____________________\n\n"; }

int main() {
  Stack<char> stackObj;

  try {
    cout << "Attempt to peek element in an empty stack: \n";
    cout << stackObj.peek() << "\n";
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << '\n';
  }

  separator();
  cout << "Read elements in Stack of 10 elements \n";
  cin >> stackObj;

  cout << "\nDisplay Stack of 10 elements: \n";
  cout << stackObj;

  separator();

  try {
    cout << "Attempt to add a new element in a full stack: \n";
    stackObj.add('@');
    cout << "Extended Stack: " << stackObj << "\n";
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << '\n';
  }

  separator();

  try {
    cout << "Remove Stack elements until it becomes empty and throw and error: "
            "\n";

    char placeholder;
    cout << "Stack: " << stackObj << "\n";

    while (true) {
      stackObj.pop(placeholder);
      cout << "Pop -> " << placeholder << ":=> Stack: " << stackObj << "\n";
    }

  } catch (const exception &e) {
    cerr << "Error: " << e.what() << '\n';
  }

  cout << "\n";
  return 0;
}
