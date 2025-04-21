#include "phone_call.h"
#include "date.h"
#include <iostream>
using namespace std;

PhoneCall::PhoneCall(string phone) : phone(phone), createdAt(Date::now()) {
  setPrice(0.0);
}

string PhoneCall::getPhone() const { return phone; }

void PhoneCall::setPrice(const double &price) { this->price = price; }

double PhoneCall::getPrice() const { return price; }

void PhoneCall::print() const {
  cout << "- Phone: " << phone << "\n- Price: " << price
       << " DA\n- Time: " << createdAt.toString() << "\n";
}

string PhoneCall::getCallDate() const { return createdAt.getDateTime(); }

double PhoneCall::calculateCost() const { return 0.0; }

IncomingPhoneCall::IncomingPhoneCall(string phone) : PhoneCall(phone) {
  setPrice(2);
}

void IncomingPhoneCall::print() const {
  PhoneCall::print();
  cout << "- Cost: " << calculateCost() << " DA\n";
}

double IncomingPhoneCall::calculateCost() const { return getPrice(); }

OutgoingPhoneCall::OutgoingPhoneCall(string phone, int time)
    : PhoneCall(phone), timeInMinutes(time) {
  setPrice(10);
}

double OutgoingPhoneCall::calculateCost() const {
  return timeInMinutes * getPrice();
}

void OutgoingPhoneCall::print() const {
  PhoneCall::print();
  cout << "- Minutes: " << timeInMinutes << "mins \n";
  cout << "- Price per minute: " << getPrice() << " DA \n";
  cout << "- Cost: " << calculateCost() << " DA \n";
}