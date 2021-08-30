#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;


const time_t FIRST = 946681200;   //1.1.2000
const time_t LAST = 4102444800;	//1.1.2100
const time_t sec_per_day = 86400;


class Budget {

public:
	Budget(int n) {
		this->n = n;
		this->profit.resize((LAST-FIRST)/sec_per_day, 0.0);
	}

	tuple<time_t, time_t> Dates(string oper) {
		string year, month, day;
		getline(cin, year, '-');
		getline(cin, month, '-');
		getline(cin, day, ' ');

		pair<time_t, time_t> res;
		struct tm first = {0,0,0, stoi(day), stoi(month)-1, stoi(year)-1900};
		time_t first_t = mktime(&first);

		getline(cin, year, '-');
		getline(cin, month, '-');
		if (oper == "Earn") {
			getline(cin, day, ' ');
		}
		else {
			getline(cin, day);
		}

		struct tm second = {0,0,0, stoi(day), stoi(month)-1, stoi(year)-1900};
		time_t second_t = mktime(&second);
		return make_tuple(first_t, second_t);
	}

	void Oper() {
		string oper;

		for (int i = 0; i<n; ++i) {
			// pair<time_t, time_t> rangeDates = this->Dates(oper);
			getline(cin, oper, ' ');
			time_t first, second;
			tie(first, second) = this->Dates(oper);
			first = (first-FIRST)/sec_per_day;
			second = (second-FIRST) / sec_per_day;

			if (oper == "Earn"){
				double value;
				cin>>value;
				int range = second-first+1;
				value/= range;
				
				for (int j=first; j<=second; ++j)
					this->profit[j] += value;
			}
			else {
				cout<<accumulate(this->profit.begin()+first, this->profit.begin()+second+1, 0.0)<<endl;
				
			}
		}
	}


private:
	int n;
	vector<double> profit;
};





int main() {
	string n1;
	getline(cin, n1);
	int n = stoi(n1);

	cout.precision(25);
	Budget budget(n);
	budget.Oper();
	return 0;
	
}