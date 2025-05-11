## Exercise 2: Account Class Implementation

This exercise demonstrates the implementation of an `Account` class in C++ to manage basic banking operations such as deposits and withdrawals. The class includes error handling using custom exceptions.

---

This Tutorial covers Exception handling in C++. For full exercise details, see [tutor_12.pdf](tutor_12.pdf).

### Features

1. **Account Initialization**:

   - Default constructor initializes the balance to 0.
   - Parameterized constructor allows setting an initial deposit.

2. **Deposit Method**:

   - Adds a positive amount to the account balance.
   - Throws an `InsufficientBlance` exception if the deposit amount is invalid.

3. **Withdraw Method**:

   - Deducts a specified amount from the account balance.
   - Throws an `InvalidArgument` exception if the withdrawal amount exceeds the balance or is negative.

4. **Error Handling**:
   - Custom exceptions (`InsufficientBlance` and `InvalidArgument`) are used to handle invalid operations.

### Example Usage

```cpp
Account acc1 = Account(100);
cout << "Account 1 Balance: " << acc1.getBalance() << "\n";

acc1.deposit(50);
cout << "Account 1 Balance after deposit: " << acc1.getBalance() << "\n";

acc1.withdraw(30);
cout << "Account 1 Balance after withdrawal: " << acc1.getBalance() << "\n";
```
