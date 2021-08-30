#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n, t;
	int64_t  sum = 0;

	
	cin>>n;
	vector<int> v(n);

	for (int i=0; i<n; ++i) {
		cin>>t;
		sum+=t;
		v[i] = t;
	}
	int avg = sum/n;
	// cout<< avg<<" ";


	vector<int> vGt;
	for (int i=0; i<n; ++i) {
		if (v[i] > avg) {
			vGt.push_back(i);
		}
	}
	cout<<vGt.size()<<"\n";
	for (auto& i: vGt) {
			cout<<i<<" ";
	}
	return 0;
}

