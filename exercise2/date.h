#pragma once
#include <iostream>
using namespace std;

struct Time {
  int hour, minute, seconds;
};

class Date {
  int hour, minutes, seconds, day, month, year;

public:
  Date(const Date &);
  Date(int hour = 0, int minute = 0, int second = 0, int day = 0, int month = 0,
       int year = 0);
  Date &operator=(const Date &);
  string getDateTime() const;
  string getDate() const;
  Time getTime() const;
  string toString() const;
  void setAll(const int &hour = 0, const int &minutes = 0,
              const int &seconds = 0, const int &day = 0, const int &month = 0,
              const int &year = 0);
  static Date now();
};