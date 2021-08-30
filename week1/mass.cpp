#include <iostream>
#include <vector>

using namespace std;


int main() {

	uint32_t n, r;
	cin>>n>>r;

	uint32_t w,h,d;
	uint64_t m = 0;

	for ( uint32_t i=0; i<n; ++i ) {
		cin>>w>>h>>d;
		m += static_cast<uint64_t>(w)*h*d;
	}
	m *= r;
	cout<<m;




	return 0;
}

