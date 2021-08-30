#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

struct tm FIRST_TM = {0,0,0, 1, 1-1, 1700-1900}; 
struct tm LAST_TM = {0,0,0, 1, 1-1, 2100-1900}; 
const time_t FIRST = mktime(&FIRST_TM);   //1.1.2000
const time_t LAST = mktime(&LAST_TM);	//1.1.2100
const time_t sec_per_day = 86400;


class Budget {

public:

	Budget() {
		int count = (LAST-FIRST)/sec_per_day;
		profit.resize(count, 0.0);
		partial.resize(count, 0.0);
	}


	time_t Dates(bool isOneDate) {
		string year, month, day;
		getline(cin, year, '-');
		getline(cin, month, '-');
		if (isOneDate) {
			getline(cin, day, ' ');
		}
		else {
			getline(cin, day);
		}
		struct tm first = {0,0,0, stoi(day), stoi(month)-1, stoi(year)-1900};
		time_t first_t = mktime(&first);
		return first_t;		
	}



	void Oper() {

		string n1, m1;

		getline(cin, n1);
		this->n = stoi(n1);
		Earn();

		getline(cin, m1);
		this->m = stoi(m1);
		Check();
	}

	void Earn() {
		for (int i = 0; i<this->n; ++i) {

			time_t date = Dates(true);
			date = (date-FIRST)/sec_per_day;

			
			uint64_t value;
			string valueStr;
			getline(cin, valueStr);
			value = stoi(valueStr);			
			this->profit[date] = value;			
		}

		partial_sum(profit.begin(), profit.end(), partial.begin());

	}

	void Check() {
		for (int i = 0; i<this->m; ++i) {

			time_t first, second;
			first = Dates(true);
			second = Dates(false);
			first = (first-FIRST)/sec_per_day;
			second = (second-FIRST) / sec_per_day;
			if (first>0) {
				cout<<this->partial[second]-this->partial[first-1];
			} else {
				cout<<this->partial[second];
			}
			// cout<<accumulate(this->profit.begin()+first, this->profit.begin()+second+1, 0.0)<<endl;
		}
	}

private:
	int n, m;
	vector<uint64_t> profit;
	vector<uint64_t> partial;

};





int main() {

	cout.precision(25);
	Budget budget;
	budget.Oper();
	return 0;
	
}