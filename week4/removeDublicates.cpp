#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;



template <class T>
void RemoveDuplicates(vector<T>& v) {
	// sort(v.begin(), v.end());
	// auto it = unique(v.begin(), v.end());
	// v.erase(it, end(v));

	unordered_set<T> s;
	for (T i : v)
	    s.insert(i);
	v.assign( s.begin(), s.end() );
}



int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}