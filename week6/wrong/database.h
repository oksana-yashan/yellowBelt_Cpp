#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <set>

#include "date.h"

class Database
{
public:
	void Add(const Date date, const string event);
	void Print(ostream &os) const;

	template <typename Func>
	int RemoveIf(const Func &predicate);

	template <typename Func>
	vector<pair<Date, string>> FindIf(const Func &predicate);

	string Last(Date date);

	map<Date, pair<set<string>, vector<set<string>::iterator>>> db;
};

template <typename Func>
int Database::RemoveIf(const Func &predicate)
{
	int count = 0;
	for (auto &el : db)
	{
		auto it = stable_partition(el.second.second.begin(),
								   el.second.second.end(), [&](auto &event)
								   {
									   if (predicate(el.first, *event))
									   {
										   ++count;
										   el.second.first.erase(*event);
										   return false;
									   }
									   return true;
								   });
		el.second.second.erase(it, el.second.second.end());
	}

	for (auto erase_it = db.cbegin(), next = erase_it; erase_it != db.cend(); erase_it = next)
	{
		++next;
		if (erase_it->second.first.empty())
			db.erase(erase_it);
	}
	return count;
}

template <typename Func>
vector<pair<Date, string>> Database::FindIf(const Func &predicate)
{
	// vector<pair<Date, string>> tmp;

	// for (const auto &el : db)
	// {

	// 	auto it = find_if(el.second.second.begin(), el.second.second.end(),
	// 					  [&](auto &event)
	// 					  {
	// 						//   cout << *event;
	// 						//   auto nxt = next(event);
	// 						//   if (*nxt != "")
	// 						// 	  cout << " exists "<<*nxt<<" ";
	// 						  if (predicate(el.first, *event))
	// 						  {
	// 							  tmp.push_back(make_pair(el.first, *event));
	// 							//   cout << "true" << endl;
	// 							  return true;
	// 						  }
	// 						//   cout << "false" << endl;
	// 						  return false;
	// 					  });
	// }
	// return tmp;

	vector<pair<Date, string>> output;
	for(auto date_it = db.begin(); date_it != db.end(); date_it = next(date_it)) {
		for(auto event_it = date_it->second.second.begin(); event_it != date_it->second.second.end(); event_it = next(event_it)) {
			if(predicate(date_it->first, *(*event_it))) {
				output.push_back(make_pair(date_it->first, *(*event_it)));
			}
		}
	}

	return output;
}
