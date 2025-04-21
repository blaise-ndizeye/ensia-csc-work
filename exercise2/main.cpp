#include "phone_call.h"
#include <iostream>
using namespace std;

int main() {
  IncomingPhoneCall incoming1("+2135123789");
  IncomingPhoneCall incoming2("+2035123009");
  IncomingPhoneCall incoming3("+1112378922");
  IncomingPhoneCall incoming4("+1035123789");

  OutgoingPhoneCall outgoing1("+2135123789", 17);
  OutgoingPhoneCall outgoing2("+2135123789", 100);
  OutgoingPhoneCall outgoing3("+2135123789", 1);
  OutgoingPhoneCall outgoing4("+2135123789", 80);

  cout << "Incoming call: \n";
  incoming1.print();
  cout << "\nOutgoing call: \n";
  outgoing1.print();

  PhoneCall *phoneCalls[]{&incoming1, &outgoing1, &incoming2, &outgoing3,
                          &incoming3, &outgoing2, &incoming4, &outgoing4};

  double totalCost = 0.0;

  cout << "\n______Display all phone calls___________ \n\n";

  for (auto phoneCall : phoneCalls) {
    IncomingPhoneCall *inc = dynamic_cast<IncomingPhoneCall *>(phoneCall);

    if (inc != nullptr) {
      cout << "Incoming call: \n";
    } else {
      cout << "Outgoing call: \n";
    }

    totalCost += phoneCall->calculateCost();
    phoneCall->print();
    cout << "\n";
  }

  cout << "Total cost for all phone calls: " << totalCost << " DA\n";

  return 0;
}