#include "database.h"

void Database::Add(const Date date, const string event)
{
    // pair<iterator, bool> isInserted = db[date].first.insert(event);
    auto isInserted = db[date].first.insert(event);
    if (isInserted.second)
    {
        db[date].second.push_back(isInserted.first);
    }
}

void Database::Print(ostream &os) const
{
    for (auto &el : db)
    {
        for (auto it : el.second.second)
        {
            cout << el.first << " " << *it << endl;
        }
    }
}

string Database::Last(Date date)
{
    const auto itBound = db.upper_bound(date);
    if (itBound == db.begin())
        throw invalid_argument("No entries");
    return prev(itBound)->first.DateToStr() + " " + *prev(itBound)->second.second.back();
}