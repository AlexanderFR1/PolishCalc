#include "gtest\gtest.h"
#include <string.h>
/*#include "charQueue.h"
#include "charStack.h"
#include "floatResult.h"*/
#include "headerForMethods.h"

using namespace std;

TEST(PolishTests,simpleCalculating)
{
	float rez;
	std::string primer;
	primer="3+4";
	charQueue polishQue(10);
	polishQue=makePolish(primer);
	rez=calculate(polishQue);
	EXPECT_EQ(7,rez);
}
