#include "vector.h"
#include <iostream>
#include <sstream>
using namespace std;

string separator(string text = "Reset all objects to initial values") {
  ostringstream sep;
  sep << "\n______________" << text << "_________________\n";
  return sep.str();
}

int main() {

  int data1[3]{4, 5, 6};
  int data2[3]{9, 7, 4};
  int data3[3]{1, 0, 1};
  int data4[3]{0, 1, 1};

  cout << separator("Raw vectors");

  Vector vector1(3), vector2(3);
  vector1.setAll(3, data1);
  vector2.setAll(3, data2);

  cout << "\nvector1 \n";
  vector1.print();

  cout << "\nvector2 \n";
  vector2.print();

  vector1.sumVect(vector2);

  cout << "\nvector1.sumVect(vector2) -> vector1 \n";
  vector1.print();

  vector1.prodVect(vector2);
  cout << "\nvector1.prodVect(vector2) -> vector1 \n";
  vector1.print();

  cout << separator("BitVector");

  BitVector bitVector1(3), bitVector2(3);
  bitVector1.setAll(3, data3);
  bitVector2.setAll(3, data4);

  cout << "\nbitVector1 \n";
  bitVector1.print();

  cout << "\nbitVector2 \n";
  bitVector2.print();

  bitVector1.sumVect(bitVector2);

  cout << "\nbitVector1.sumVect(bitVector2) -> bitVector1 \n";
  bitVector1.print();

  bitVector1.prodVect(bitVector2);
  cout << "\nbitVector1.prodVect(bitVector2) -> bitVector2 \n";
  bitVector1.print();

  cout << separator();

  vector1.setAll(3, data1);
  vector2.setAll(3, data2);
  bitVector1.setAll(3, data3);
  bitVector2.setAll(3, data4);

  cout << "\nvector1 \n";
  vector1.print();
  cout << "\nvector2 \n";
  vector2.print();
  cout << "\nbitVector1 \n";
  bitVector1.print();
  cout << "\nbitVector2 \n";
  bitVector2.print();

  cout << separator("Pointers aiming to the same type objects");

  Vector *vectPtr1 = new Vector(1);
  vectPtr1->setAll(vector1.getSize(), vector1.getData());
  Vector *vectPtr2 = new Vector(1);
  vectPtr2->setAll(vector2.getSize(), vector2.getData());

  BitVector *bitVectPtr1 = new BitVector(1);
  bitVectPtr1->setAll(bitVector1.getSize(), bitVector1.getData());
  BitVector *bitVectPtr2 = new BitVector(1);
  bitVectPtr2->setAll(bitVector2.getSize(), bitVector2.getData());

  cout << "\nvectPtr1->vector1 and bitVectPtr1->bitVector1\n";
  cout << "\nvectPtr1 \n";
  vectPtr1->print();
  cout << "\nvectPtr2 \n";
  vectPtr2->print();
  cout << "\nbitVectPtr1 \n";
  bitVectPtr1->print();
  cout << "\nbitVectPtr2 \n";
  bitVectPtr2->print();

  vectPtr1->sumVect(vector2);
  cout << "\nvectPtr1->sumVect(vector2) -> vectPtr1\n";
  vectPtr1->print();

  vectPtr1->prodVect(vector2);
  cout << "\nvectPtr1->prodVect(vector2) -> vectPtr1\n";
  vectPtr1->print();

  bitVectPtr1->sumVect(bitVector1);
  cout << "\nbitVectPtr1->sumVect(bitVector1) -> bitVectPtr1 \n";
  bitVectPtr1->print();

  bitVectPtr1->prodVect(bitVector1);
  cout << "\nbitVectPtr1->prodVect(bitVector1) -> bitVectPtr1 \n";
  bitVectPtr1->print();

  cout << separator("Pointers aiming to different type objects");

  vectPtr1->setAll(3, data1);
  vectPtr2->setAll(3, data2);
  bitVectPtr1->setAll(3, data3);
  bitVectPtr2->setAll(3, data4);

  delete vectPtr1; // Clean up original objects
  delete vectPtr2;

  vectPtr1 = new BitVector(3); // Create new BitVector objects
  vectPtr2 = new BitVector(3);
  vectPtr1->setAll(3, data3);
  vectPtr2->setAll(3, data4);

  vectPtr1->add(1);
  vectPtr1->add(0);
  vectPtr1->add(1);
  vectPtr1->add(1);
  vectPtr2->add(1);
  vectPtr2->add(0);
  vectPtr2->add(1);
  vectPtr2->add(1);

  cout << "\nvectPtr1->&bitVector1 and bitVectPtr1->&vector1 \n";
  cout << "\nvectPtr1 \n";
  vectPtr1->print();
  cout << "\nvectPtr2 \n";
  vectPtr2->print();

  vectPtr1->sumVect(*vectPtr2);
  cout << "\nvectPtr1->sumVect(*vectPtr2) -> vectPtr1 \n";
  vectPtr1->print();

  vectPtr2->sumVect(*vectPtr1);
  cout << "\nvectPtr2->sumVect(*vectPtr1) -> vectPtr2 \n";
  vectPtr2->print();

  vectPtr1->prodVect(*vectPtr2);
  cout << "\nvectPtr1->prodVect(*vectPtr2) -> vectPtr1 \n";
  vectPtr1->print();

  vectPtr2->prodVect(*vectPtr1);
  cout << "\nvectPtr2->prodVect(*vectPtr1) -> vectPtr2 \n";
  vectPtr2->print();

  cout << "\n";

  delete vectPtr1;
  delete vectPtr2;
  delete bitVectPtr1;
  delete bitVectPtr2;

  return 0;
}