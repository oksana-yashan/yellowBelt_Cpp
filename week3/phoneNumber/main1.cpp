
#include "testrunner.h"
#include "phoneNumber.h"


int main() {
	TestRunner r;
	r.RunTest(TestFullNumber, "TestFullNumber");
	r.RunTest(TestEmpty, "TestEmpty");
	
}