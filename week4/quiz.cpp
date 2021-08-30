#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

using namespace std;


void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {

	// int n;
	// cin>>n;

	set<int> s = {1,2,3};
	vector<int> v = {1,2,3};
	cout<< is_permutation(s.begin(), s.end(), v.begin());

	cout<<is_permutation(v.begin(), v.end(), v.begin());

	string str = "hello";
	cout<<is_heap(str.begin(), str.end());

	//error
	// auto res = next_permutation(s.begin(), s.end());

	// auto res = is_permutation(s.begin(), s.end(), back_inserter(v));

	auto res = next_permutation(str.begin(), str.end());	

	//outputIt != set
	// partial_sum(v.begin(), v.end(), s.begin());


	vector<int> vec = {1,2,3,6,5,4,3,2,1,2,5,3,2,1, 6};
	auto res2 = is_sorted_until(vec.rbegin(), vec.rend());	//1
	auto res3 = is_sorted_until(vec.begin(), vec.end());	//5
	auto res4 = is_sorted_until(vec.end(), vec.begin()); //0
	cout<<*res2;
	cout<<*res3;
	cout<<*res4;
	return 0;
}