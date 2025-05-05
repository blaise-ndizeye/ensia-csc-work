#include "../lib/linked_list.h"
#include <iostream>
using namespace std;

int main() {
  LinkedList<int> list;
  list.add(14);
  list.add(20);
  list.add(26);
  list.printList();

  cout << "\n";

  LinkedList l2(list);
  l2.printList();

  return 0;
}