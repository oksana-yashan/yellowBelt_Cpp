
#include "testrunner.h"
#include "sum_reverse_sort.h"


int main() {
	TestRunner r;
	r.RunTest(TestSum, "TestSum");
	r.RunTest(TestReverse, "TestReverse");
	r.RunTest(TestSort, "TestSort");

}
