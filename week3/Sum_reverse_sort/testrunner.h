#pragma once
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr<< test_name<< "OK"<<endl;
    } catch (runtime_error& e) {
      ++fail_count;
      cerr<<test_name<<" fail: "<<e.what()<<endl;
    }
  }


  ~TestRunner() ;

private:
  int fail_count=0;
};
