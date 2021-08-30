#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

template <typename KeyType, typename ValueType>
ValueType& GetRefStrict( map<KeyType, ValueType>& m, KeyType k) {
	if (m.count(k) == 0) {
		throw runtime_error("No such key in dictionary");
	}
	return m[k];
}


// string& GetRefStrict( map<int, string>& m, int k) {
// 	if (m.count(k) == 0) {
// 		throw runtime_error("No such key in dictionary");
// 	}
// 	return m[k];
// }


int main() {

	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	return 0;
}