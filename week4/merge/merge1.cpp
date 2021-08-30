
#include <iostream>  
#include <algorithm>   
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;




template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
		if (range_end - range_begin < 2) 
				return ;

		vector<typename RandomIt::value_type> v(range_begin, range_end);
		auto mid = v.begin() + (range_end-range_begin)/2;

		MergeSort(v.begin(), mid);
		MergeSort(mid, v.end());

		merge(v.begin(), mid,
					mid, v.end(),
					range_begin);

}


int main() {
	  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
	  MergeSort(begin(v), end(v));
	  for (int x : v) {
	    cout << x << " ";
	  }
	  cout << endl;
	  return 0;
}