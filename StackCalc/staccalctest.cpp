#include <string>
#include <vector>

#include "staccalctest.h"

using namespace std;

void StacCalcTest::separatorTest()
{
	string input = "2 3 +";
	vector<string> output = separator(input);
	QVERIFY(output.size() == 3);
	QCOMPARE(output[0], "2");
	QCOMPARE(output[1], "3");
	QCOMPARE(output[2], "+");
}
