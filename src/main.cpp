#include "../lib/coin.h"
#include "../lib/coin10.h"
#include "../lib/coin20.h"
#include "../lib/coin50.h"
#include <iostream>
using namespace std;

void evaluateToss(Coin *coin) {
  bool tossValue = coin->toss();

  if (tossValue) {
    Coin::incrementBalance(coin->getValue());
  }
}

int main() {
  Coin10 coin10;
  Coin20 coin20;
  Coin50 coin50;

  Coin::setBalance(0.0);
  cout << "Set the balance to zero: " << Coin::getBalance() << "DA \n";

  int i = 0;
  while (Coin::getBalance() < 100) {
    evaluateToss(&coin10);
    evaluateToss(&coin20);
    evaluateToss(&coin50);

    cout << "[Round-" << i + 1 << "] Balance: " << Coin::getBalance() << "DA";
    cout << "\n";
    i++;
  }

  if (Coin::getBalance() == 100) {
    cout << "\nYou have WON the game! \n";
  } else {
    cout << "\nYou have LOST the game! \n";
  }

  return 0;
}