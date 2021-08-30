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
	sort(nums.begin(),nums.end(), myfunction);
	return nums;

}



void TestSum() {
	AssertEqual(Sum(1,2), 3);
	AssertEqual(Sum(-2,5-3), 0);
}

void TestReverse() {
  AssertEqual(Reverse("hello"), "olleh");
  AssertEqual(Reverse("hellow"), "wolleh");
  AssertEqual(Reverse("12wd"), "dw12");
}

void TestSort() {
  AssertEqual(Sort({2,5,2,3}), {2,2,3,5});
}