#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> split;

		// istringstream i_stream(s);
	  //   string tmp;

	  //   while (i_stream >> tmp)
	  //   {
	  //       split.push_back(tmp);
	  //   }
	

	auto it_endW = --begin(s);

	while (it_endW < end(s)) {

		auto it_startW = ++it_endW;
		// it_endW = find_if(it_startW, end(s), 
		// 							[](char i) {return i==' ';});
		it_endW = find_if(it_startW, end(s), ' ');

		// cout<<*(--it_endW)<<endl;
		// ++it_endW;
		split.push_back(string (it_startW, it_endW));

	}
	return split;
}




int main() {
	  string s = "C Cpp Java Python";

	  vector<string> words = SplitIntoWords(s);
	  cout << words.size() << " ";
	  for (auto it = begin(words); it != end(words); ++it) {
	    if (it != begin(words)) {
	      cout << "/";
	    }
	    cout << *it;
	  }
	  cout << endl;
	  
	  return 0;
}