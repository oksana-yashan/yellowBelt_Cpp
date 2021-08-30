#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


// class Name {
// public:
// 	string firstName = "";
// 	string lastName = "";
// };

string GetNearestName(map<int, string>& name, int year) {
	auto uB = name.upper_bound(year);
	string n;
	if (uB != name.begin())
			n = (--uB)->second;
	return n;
}

class Person {

public:
	void ChangeFirstName(int year, const string& firstName) {
		firstNames[year] = firstName;
	}

	void ChangeLastName(int year, const string& lastName) {
		lastNames[year] = lastName;
	}

	string GetFullName(int year) {

		if (firstNames.size() == 0 || lastNames.size() == 0 ) {
			return "Incognito";
		}
		string fN = GetNearestName(firstNames, year);
		string lN = GetNearestName(lastNames, year);		

		if (fN.empty() && lN.empty()) {
      return "Incognito";
    } else if (fN.empty()) {
      return lN + " with unknown first name";
    } else if (lN.empty()) {
      return fN + " with unknown last name";
    } else {
      return fN + " " + lN;
    }
	}

private:
	map<int, string> firstNames;
	map<int, string> lastNames;

};



// void PrintSortedStrings( SortedStrings& ss) {
// 	for (const string& s : ss.GetSortedStrings()) {
// 		cout <<s<<" ";
// 	}
// 	cout<<endl;
// }



int main() {

	Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  

	return 0;
}