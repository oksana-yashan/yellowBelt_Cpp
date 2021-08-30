#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

// void PrintVectorPart(const vector<int>& v) {
// 	auto it = find_if(begin(v), end(v), 
// 									[](int i) {return i<0;});

// 	for (auto i=it; it!=begin(v);){
// 		cout<<*(--it)<<" ";
// 	}
// }


template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	// auto it = find_if(begin(elements), end(elements), 
	// 					[border](T i) {return i == border;});
	// // cout<<*it<<endl;
	
	// vector<T> r;
	// if (it != end(elements)){
	// 	for (auto i = it; i!= --end(elements); ){
	// 	r.push_back(*(++i));
	// 	}
	// }


	// auto it = find_if(begin(elements), end(elements), 
	// 					[border](T i) {return i > border;});
	// vector<T> r;
	// if (it != end(elements)){
	// 	for (auto i = it; i!= end(elements); i++){
	// 		r.push_back(*i);
	// 	}
	// }
	// return r;


	auto it = find_if(begin(elements), end(elements), 
						[border](T i) {return i > border;});
	return {it, end(elements)};
}




int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}













// template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
// bool
// __equal(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
//         _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
//       random_access_iterator_tag, random_access_iterator_tag )
// {
//     if ( _VSTD::distance(__first1, __last1) != _VSTD::distance(__first2, __last2))
//         return false;
//     return _VSTD::equal<_RandomAccessIterator1, _RandomAccessIterator2,
//                         typename add_lvalue_reference<_BinaryPredicate>::type>
//                        (__first1, __last1, __first2, __pred );
// }