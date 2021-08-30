#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;


void Print(vector<string>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {

	vector<string> v;
	v.push_back("str1");
	v.push_back("str2");
	v.push_back("str3");
	v.push_back("str4");
	v.push_back("str5");
	v.push_back("str6");
	string s = "str5Changed";
	
	vector<string>& s2 = v;
	for (auto& i:s2) {
		if (i == "str5") {
			i = "s";
		}
	}

	Print(s2);
	Print(v);
	return 0;
}