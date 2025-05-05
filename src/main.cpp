#include "../lib/linked_list.h"
#include <iostream>
using namespace std;

int main() {
  LinkedList<int> list1;
  list1.add(14);
  list1.add(20);
  list1.add(26);

  cout << "List1 <int>: ";
  list1.printList();

  LinkedList list2(list1);

  cout << "\nList2 <int>: ";
  list2.printList();

  LinkedList<string> list3;
  list3.add("Blaise");
  list3.add("Shema");
  list3.add("Leandre");
  list3.add("Omar");
  list3.add("Livine");

  cout << "\nList3 <string>: ";
  list3.printList();

  cout << "\nInsert 199 at position 2 in List1<int>: ";
  list1.insertAt(2, 199);
  list1.printList();

  cout << "\nInsert 'Hello' at position 2 in List3<string>: ";
  list3.insertAt(2, "Hello");
  list3.printList();

  cout << "\nDelete 20 from List2<int>: ";
  list2.remove(20);
  list2.printList();

  cout << "\nDelete 'Omar' from List3<string>: ";
  list3.remove("Omar");
  list3.printList();

  cout << "\n Assign List2<int> to List1<int> => list1 = list2: ";
  list1 = list2;
  list1.printList();

  cout << "\n";
  return 0;
}