#pragma once
#include "date.h"
#include <iostream>
using namespace std;

class PhoneCall {
  string phone;
  double price;
  Date createdAt;

public:
  PhoneCall(string phone = "");
  string getPhone() const;
  void setPrice(const double &);
  double getPrice() const;
  virtual void print() const;
  virtual string getCallDate() const;
  virtual double calculateCost() const;
  virtual ~PhoneCall() = default;
};

class IncomingPhoneCall : public PhoneCall {
public:
  IncomingPhoneCall(string phone);     // sets price to 2DA
  virtual void print() const override; // shows phone number, price and cost
  virtual double calculateCost() const override;
  virtual ~IncomingPhoneCall() = default;
};

class OutgoingPhoneCall : public PhoneCall {
  int timeInMinutes;

public:
  OutgoingPhoneCall(string phone, int time); // sets price to 10DA per minute
  virtual void print() const
      override; // shows phone number, price per minute, minutes, and total cost
  virtual double calculateCost() const override;
  virtual ~OutgoingPhoneCall() = default;
};