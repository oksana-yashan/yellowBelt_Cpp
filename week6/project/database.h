#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <set>

#include "date.h"
#include "storage.h"

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

	map<Date, Storage> db;
};

template <typename Func>
int Database::RemoveIf(const Func &predicate)
{
	int count = 0;
	for (auto &el : db)
	{
		auto it = stable_partition(el.second.s.begin(),
								   el.second.s.end(), [&](auto &event)
								   {
									   if (predicate(el.first, event))

									   {
										   ++count;
										   remove(el.second.v.begin(),
												  el.second.v.end(), event);
										   return false;
									   }
									   return true;
								   });
		el.second.s.erase(it, el.second.s.end());
	}

	for (auto erase_it = db.cbegin(), next = erase_it; erase_it != db.cend(); erase_it = next)
	{
		++next;
		if (erase_it->second.s.empty())
			db.erase(erase_it);
	}
	return count;
}

template <typename Func>
vector<pair<Date, string>> Database::FindIf(const Func &predicate)
{
	vector<pair<Date, string>> tmp;

	for (const auto &el : db)
	{

		auto it = find_if(el.second.s.begin(), el.second.s.end(),
						  [&](auto &event)
						  {
							  //   cout << *event;
							  //   auto nxt = next(event);
							  //   if (*nxt != "")
							  // 	  cout << " exists "<<*nxt<<" ";
							  if (predicate(el.first, event))
							  {
								  tmp.push_back(make_pair(el.first, event));
								  //   cout << "true" << endl;
								  return true;
							  }
							  //   cout << "false" << endl;
							  return false;
						  });
	}
	return tmp;
}
