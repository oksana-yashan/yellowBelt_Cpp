#include <string>
#include <vector>
#include <algorithm>

#include "tests.h"
using namespace std;

int Sum(int x, int y) {
	return x+y;
}


string Reverse(string s) {
	char temp;
	int last_index = s.size()-1;

	for (int i=0; i<s.size()/2; ++i) {
		temp = s[i];
		s[i] = s[last_index-i];
		s[last_index-i] = temp;
	}
	return s;

}

bool myfunction (int i,int j) { return (i<j); }

vector<int> Sort(vector<int>& nums) {
	sort(nums.begin(),nums.end(), [] (int i, int j){return i<j;});
	// sort(nums.begin(),nums.end(), myfunction);
	return nums;

}



void TestSum() {
	AssertEqual(Sum(1,2), 3, "test");
	AssertEqual(Sum(-2,5-3), 0, "test");
}

void TestReverse() {
  AssertEqual(Reverse("hello"), "olleh", "test");
  AssertEqual(Reverse("hellow"), "wolleh", "test");
  AssertEqual(Reverse("12wd"), "dw21", "test");
}

void TestSort() {
	vector<int> v = {2,5,2,3};
	vector<int> v2 = {2,2,3,5};
  AssertEqual(Sort(v), v2, "test");
}