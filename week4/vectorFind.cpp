#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int>& v) {
	auto it = find_if(begin(v), end(v), 
									[](int i) {return i<0;});

	// while ( it != begin(v) ) {
	// 	--it; 
	// 	cout<<*it<<" ";
	// }

	for (auto i=it; it!=begin(v);){
		cout<<*(--it)<<" ";
	}
}

int main() {
	  PrintVectorPart({6, 1, 8, -5, 4});
	  cout << endl;
	  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	  cout << endl;
	  PrintVectorPart({6, 1, 8, 5, 4});
	  cout << endl;
	  return 0;
}