
#include <iostream>  
#include <algorithm>   
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;




template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
		int n = range_end - range_begin;
		if (n < 3) 
				return ;

		vector<typename RandomIt::value_type> v(range_begin, range_end);
		auto mid1_3 = v.begin() + n/3;
		auto mid2_3 = mid1_3 + n/3;

		MergeSort(v.begin(), mid1_3);
		MergeSort(mid1_3, mid2_3);
		MergeSort(mid2_3, v.end());

		vector<typename RandomIt::value_type> tmp;
		merge(v.begin(), mid1_3,
					mid1_3, mid2_3,
					back_inserter(tmp));

		RandomIt range_mid = range_begin + n/2;

		merge(tmp.begin(), tmp.end(),
					mid2_3, v.end(),
					range_begin);

}


int main() {
	  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
	  MergeSort(begin(v), end(v));
	  for (int x : v) {
	    cout << x << " ";
	  }
	  cout << endl;
	  return 0;
}