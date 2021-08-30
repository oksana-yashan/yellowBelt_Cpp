#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "tests.h"
using namespace std;



void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

