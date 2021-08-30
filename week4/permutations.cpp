// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;


int main () {
  int n;
  cin>>n;

  vector<int> v(n);
  for (int i = n; i>0; --i) {
    v[n-i] = i;
  }

  // iota(v.begin(), v.end(), 1);
  // reverse(v.begin(), v.end());

  

  do {
    for (auto el: v) {
      cout<< el<< " ";
    }
    // copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout <<endl;
  } while ( prev_permutation(v.begin(), v.end()) );

  return 0;
}