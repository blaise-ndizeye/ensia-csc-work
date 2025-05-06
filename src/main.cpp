#include "../lib/queue.h"
#include <iostream>
using namespace std;

int main() {
  Queue<int> integers;
  Queue<string> words(5);

  integers.push(4);
  integers.push(8);
  integers.push(9);
  integers.push(1);
  integers.push(3);
  integers.push(2);

  words.push("Blaise");
  words.push("Lea");
  words.push("Shema");
  words.push("Omar");
  words.push("Patrick");

  cout << "Queue<int>: ";
  integers.print();

  cout << "\nQueue<string>: ";
  words.print();

  int poppedElement1 = 0;
  if (integers.pop(poppedElement1)) {
    cout << "\n" << poppedElement1 << " is removed from Queue<int>\n";
  } else {
    cout << "\nPopping element from Queue<int> failed!\n";
  }

  cout << "\nQueue<int>: ";
  integers.print();

  string poppedElement2 = "";
  if (words.pop(poppedElement2)) {
    cout << "\n" << poppedElement2 << " is removed from Queue<string>\n";
  } else {
    cout << "\nPopping element from Queue<string> failed!\n";
  }

  cout << "Queue<string>: ";
  words.print();

  cout << "\n\nOverload Queue<string>: \n";
  words.push("Joshua");

  if (words.push("Hello")) {
    cout << "\nUnexpected!\n";
  } else {
    cout << "Can not overload Queue<string> of size 5\n";
  }

  cout << "Queue<string>: ";
  words.print();

  cout << "\n";
  return 0;
}