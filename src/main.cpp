#include "../lib/pair.h"
#include <iostream>
using namespace std;

int main() {
  Pair<int, int> integers(1, 3);
  Pair reals(4.5, 3.3);
  Pair<string, int> map("Hello world", 101);

  cout << "Get the first element from Pair<int, int>: " << integers.get_first()
       << "\n";

  cout << "\nGet the second for element from Pair<double, double>: "
       << integers.get_second() << "\n";

  cout << "\nPrint the Pair<string, int>: ";
  print_pair(map);

  cout << "\nSet the first element of Pair<string, int> to 'C++': ";
  map.get_first() = "C++";
  print_pair(map);

  cout << "\n";
  return 0;
}