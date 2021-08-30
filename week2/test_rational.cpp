#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};




class Rational {
public:
  Rational(){
    numerator = 0;
    denominator = 1;
  }
  Rational( int n,  int d) {

    if (n == 0) {
      // Rational();   //error but i don`t know why((
      numerator = 0;
      denominator = 1;
    }
        else if( d == 0 ){
            throw invalid_argument("Invalid argument");
        }

    else {
      if ((n <0 && d<0) || (n >=0 && d<0)) {
        n = -n; 
        d = -d;
      }

      gcd = gcd_func(abs(n), abs(d));
        if (gcd != 1) {
          n /= gcd;
          d /= gcd;
          gcd = 1;
        }
      numerator = n;
      denominator = d;

    }
    
  }

    int Numerator() const {
      return numerator;
    }
    
    int Denominator() const {
      return denominator;
    }



private:
  int numerator;
  int denominator;
  int gcd;

  int gcd_func(int f, int s) {
    while (f >0 && s >0) {
      if (f>s) {
        f = f%s;
      }
      else if (s>f) {
        s = s%f;      }
    }
    return s+f;
  }
};




void TestDefaultConstructor() {
  Rational r;
  AssertEqual(r.Numerator(), 0);
  AssertEqual(r.Denominator(), 1);
}

void TestReduction() {
  Rational r(50,100);
  AssertEqual(r.Numerator(), 1);
  AssertEqual(r.Denominator(), 2);
}

void TestNegative() {
  Rational r(-1,2);
  AssertEqual(r.Numerator(), -1);
  AssertEqual(r.Denominator(), 2);

  Rational r2(1,-2);
  AssertEqual(r2.Numerator(), -1);
  AssertEqual(r2.Denominator(), 2);
}

void TestNegativeBoth() {
  Rational r(-1,-2);
  AssertEqual(r.Numerator(), 1);
  AssertEqual(r.Denominator(), 2);
}

void TestZeroNumerator() {
  Rational r(0,2);
  AssertEqual(r.Numerator(), 0);
  AssertEqual(r.Denominator(), 1);
}




int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestReduction, "TestReduction");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestNegativeBoth, "TestNegativeBoth");
  runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
  
  return 0;
}
