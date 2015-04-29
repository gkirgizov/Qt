#include <string>
#include <vector>

#include "staccalctest.h"

using namespace std;

void StacCalcTest::separateTest()
{
	string input = "2 3 +";
	vector<string> output = CalcStack::separate(input);
	QVERIFY(output.size() == 3);
	QCOMPARE(output[0], string("2"));
	QCOMPARE(output[1], string("3"));
	QCOMPARE(output[2], string("+"));
}
