#pragma once

#include <memory>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "date.h"

using namespace std;

class Date
{
public:
    Date();
    Date(int y, int m, int d);
    int GetYear() const;
    //----------------------------------------------------------------------------------------------------
    int GetMonth() const;
    //----------------------------------------------------------------------------------------------------
    int GetDay() const;
    string DateToStr() const;

    int year;
    int day;
    int month;
};

ostream &operator<<(ostream &os, const Date &d);

bool operator<(const Date &l, const Date &r);
bool operator>(const Date &l, const Date &r);
bool operator==(const Date &l, const Date &r);
bool operator!=(const Date &l, const Date &r);
bool operator<=(const Date &l, const Date &r);
bool operator>=(const Date &l, const Date &r);



Date ParseDate(istringstream &is);