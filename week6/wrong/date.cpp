#include "date.h"
#include <iomanip>
#include <tuple>

Date::Date() : year(1), month(1), day(1) {}

Date::Date(int y, int m, int d)
{
    if (m > 12 || m < 1)
    {
        string error = "Month value is invalid: " + to_string(m);
        throw logic_error(error);
    }
    else
    {
        month = m;
    }

    if (d > 31 || d < 1)
    {
        string error = "Day value is invalid: " + to_string(d);
        throw logic_error(error);
    }
    else
    {
        day = d;
    }
    year = y;
}

ostream &operator<<(ostream &os, const Date &d)
{
    os << setw(4) << setfill('0') << d.GetYear() << "-" << setfill('0') << setw(2) << d.GetMonth() << "-" << setw(2) << setfill('0') << d.GetDay();
    return os;
}

bool operator<(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) < tie(r.year, r.month, r.day);
}

bool operator>(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) > tie(r.year, r.month, r.day);
}
bool operator==(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) == tie(r.year, r.month, r.day);
}
bool operator!=(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) != tie(r.year, r.month, r.day);
}
bool operator<=(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) <= tie(r.year, r.month, r.day);
}
bool operator>=(const Date &l, const Date &r)
{
    return tie(l.year, l.month, l.day) >= tie(r.year, r.month, r.day);
}

int Date::GetYear() const
{
    return year;
}
//----------------------------------------------------------------------------------------------------
int Date::GetMonth() const
{
    return month;
}
//----------------------------------------------------------------------------------------------------
int Date::GetDay() const
{
    return day;
}

string Date::DateToStr() const
{
    stringstream ss;
    ss << *this;
    return ss.str();
}

Date ParseDate(istringstream &is)
{
    int d, m, y;
    is >> y;
    is.ignore(1);
    is >> m;
    is.ignore(1);
    is >> d;

    Date date(y, m, d);
    return date;
}