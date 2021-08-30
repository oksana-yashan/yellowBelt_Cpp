#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// template <typename T>
// T Sqr (T& x);

// template <typename T>
// vector<T> Sqr( vector<T>& v );


// template <typename First, typename Second>
// pair<First, Second> Sqr( pair<First, Second>& p );


// template <typename Key, typename Value>
// map<Key, Value> Sqr( map<Key, Value>& m ) ;





template <typename T>
T Sqr (T& x) {
	return x*x;
}

template <typename T>
vector<T> Sqr( vector<T>& v ) {
	vector<T> v2;
	for (auto i: v) {
		v2.push_back(Sqr(i));
	} 
	return v2;
}


template <typename First, typename Second>
pair<First, Second> Sqr( pair<First, Second>& p ) {
	// pair<First, Second> p2;
	// p2.first = Sqr(p.first);
	// p2.second = Sqr(p.second);
	// return p2;
	return {Sqr(p.first), Sqr(p.second)};
}


template <typename Key, typename Value>
map<Key, Value> Sqr( map<Key, Value>& m ) {
	map<Key, Value> map1;
	for (auto pair: m) {
		map1[pair.first] = Sqr(pair.second);
	} 
	return map1;
}




int main() {

	





	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	return 0;
}