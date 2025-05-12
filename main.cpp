#include <iostream>
#include <limits>
using namespace std;

int main() {
  cin.exceptions(iostream::failbit);
  int num = 0;

  try {
    do {
      cout << "Enter a number between 1 and 10" << endl;
      // * When a something like "four" is entered instead of a number, it'll
      // * cause an infinite loop
      cin >> num;

      if (cin.peek() != '\n') {
        throw &num;
      }

      if (num < 1 || num > 10) {
        cout << "Illegal value " << num << " entered. Try again." << endl;
      }
    } while (num < 1 || num > 10);

    cout << "Value " << num << " correctly entered! Thank you." << endl;
  } catch (iostream::failure &iof) {
    cout << "Non-integer value. Please enter a number." << endl;
    cin.clear();                                         // reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear
  } catch (int *pnum) {
    cout << "Non -integer value. You entered something after " << *pnum;
    cin.clear();                                         // reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearbuffer
    *pnum = 0; // reset num to its initial value
  }

  cout << "\n";
  return 0;
}