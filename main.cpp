#include <iostream>
#include <stdexcept>
using namespace std;
using std::runtime_error;

class InsufficientBlance : public runtime_error {
public:
  InsufficientBlance(const string &msg) : runtime_error(msg) {}
};

class InvalidArgument : public runtime_error {
public:
  InvalidArgument(const string &msg) : runtime_error(msg) {}
};

class Account {
private:
  double balance;

public:
  Account() { balance = 0; }

  Account(double initialDeposit) { balance = initialDeposit; }

  double getBalance() { return balance; }

  double deposit(double amount) {
    if (amount > 0)
      balance += amount;
    else
      throw InsufficientBlance("Insufficient balance!");

    return balance;
  }

  double withdraw(double amount) {
    if ((amount > balance) || (amount < 0))
      throw InvalidArgument("Insufficient balance!");
    else
      balance -= amount;

    return balance;
  }
};

int main() {
  try {
    Account acc1 = Account(100);
    Account acc2;

    cout << "Account 1 Balance: " << acc1.getBalance() << "\n";

    acc2.withdraw(100);
    cout << "Account 1 Balance: " << acc1.getBalance() << "\n";
  } catch (exception &exc) {
    cerr << "Error occured: " << exc.what() << "\n";
  }
}