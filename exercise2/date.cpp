#include "date.h"
#include <ctime>

Date::Date(const Date &copy) { *this = copy; }

Date &Date::operator=(const Date &other) {
  hour = other.hour;
  minutes = other.minutes;
  seconds = other.seconds;
  day = other.day;
  month = other.month;
  year = other.year;

  return *this;
}

Date::Date(int hour, int minutes, int seconds, int day, int month, int year) {
  setAll(hour, minutes, seconds, day, month, year);
}

void Date::setAll(const int &hour, const int &minutes, const int &seconds,
                  const int &day, const int &month, const int &year) {
  if (hour < 0 || seconds < 0 || minutes < 0 || seconds < 0 || day < 0 ||
      month < 0 || year < 0) {
    throw invalid_argument("Please provide valid date-time parameter!");
  }

  this->hour = hour;
  this->minutes = minutes;
  this->seconds = seconds;
  this->day = day;
  this->month = month;
  this->year = year;
}

string Date::getDateTime() const { return toString(); }

string Date::getDate() const {
  return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

Time Date::getTime() const { return {hour, minutes, seconds}; }

string Date::toString() const {
  return getDate() + " " + to_string(hour) + ":" + to_string(minutes) + ":" +
         to_string(seconds);
}

Date Date::now() {
  time_t t = time(nullptr);
  tm *currentTime = localtime(&t);

  return Date(currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec,
              currentTime->tm_mday, currentTime->tm_mon + 1,
              currentTime->tm_year + 1900);
}
