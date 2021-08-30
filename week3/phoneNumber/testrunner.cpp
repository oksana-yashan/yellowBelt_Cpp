#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
#include "testrunner.h"

  

  TestRunner::~TestRunner() {
    if (fail_count > 0) {
      cerr<<fail_count<<" unit test failed.Terminate";
      exit(1);
    }
  }
