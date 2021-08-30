
#include <iostream>  
#include <algorithm>   
#include <vector>
#include <sstream>
#include <iterator>
#include <chrono>
#include <string>
using namespace std;




template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {


}




int main() {
	  int n;
	  string oper;
	  string day, month, year;
	  string day2, month2, year2;

	  cin >> n;
	  

	  for (int i = 0; i < n; ++i) {
	  	cin>>oper;
	  	if (oper == "ComputeIncome") {


	  	}
	  	else if (oper == "Earn") {
	  		
	  		getline(cin, year, '-');
	  		getline(cin, month, '-');
	  		getline(cin, day, ' ');

	  		getline(cin, year2, '-');
	  		getline(cin, month2, '-');
	  		getline(cin, day2);


	  		


		}
		  	
	  	
	  }
	  
	  return 0;
}