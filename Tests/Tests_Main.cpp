#include "gtest\gtest.h"
#include <string.h>
/*#include "charQueue.h"
#include "charStack.h"
#include "floatResult.h"*/
#include "headerForMethods.h"

using namespace std;
//==Тесты общей работоспособности===============
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
TEST(PolishTests,advancedCalculating)
{
	float rez;
	std::string primer;
	primer="2-22/2+3*4-3-4";
	charQueue polishQue(20);
	polishQue=makePolish(primer);
	rez=calculate(polishQue);
	EXPECT_EQ(-4,rez);
}
TEST(PolishTests,calculatingWithBrackets)
{
	float rez;
	std::string primer;
	primer="(22-33)*4";
	charQueue polishQue(20);
	polishQue=makePolish(primer);
	rez=calculate(polishQue);
	EXPECT_EQ(-44,rez);
}


//===Тест на деление на ноль====================
TEST(calculatingTests,divAtZero)
{
	std::string primer;
	float rez;
	charQueue polishQue(20);
	primer="1/0";
	polishQue=makePolish(primer);
	ASSERT_ANY_THROW(calculate(polishQue) );
}


//========Тесты на проверку корректности строки=============
TEST(stringTests,correctBrackets)
{
	std::string primer;
	primer="2*(22+33)-4)";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
}
TEST(stringTests,withLiters)
{
	std::string primer;
	primer="AF2*(22+33dds)-4)";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
}
TEST(stringTests,twoOperators)
{
	std::string primer;
	primer="22+66*(11-+6)";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
}
TEST(stringTests,numberOperatorEnd)
{
	std::string primer;
	primer="0+";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
	primer="1*";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
	primer="2-";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
	primer="3/";
	ASSERT_ANY_THROW(isStringCorrect(primer) );
}

//===Тесты классов====================================

TEST (customQueue, popIfEmpty)
{
	charQueue testQ(3);
	ASSERT_ANY_THROW(testQ.pop() );
}
TEST (customQueue, createQueueWithPositiveSize)
{
	ASSERT_NO_THROW(charQueue testQ(5) );
}
TEST (customQueue, create_Queue_with_Negative_Size)
{
	ASSERT_ANY_THROW(charQueue testQ(-5) );
}
TEST (customQueue, CheckWorking)
{
	charStack testQ(2);
	EXPECT_EQ(true,testQ.isEmpty() );
	EXPECT_NE(true,testQ.isFull() );
	testQ.push("1");
	EXPECT_NE(true,testQ.isEmpty() );
	EXPECT_NE(true,testQ.isFull() );
	testQ.push("a");
	EXPECT_EQ(false,testQ.isEmpty() );
	EXPECT_EQ(true,testQ.isFull() );
	testQ.pop();
	EXPECT_NE(true,testQ.isEmpty() );
	EXPECT_NE(true,testQ.isFull() );
	testQ.pop();
	EXPECT_EQ(true,testQ.isEmpty() );
	EXPECT_NE(true,testQ.isFull() );
}
TEST (customQueue, correctPushPops)
{
	charQueue testQ(2);
	testQ.push("testing");
	string temp;
	temp=testQ.pop();
	EXPECT_EQ("testing",temp);
}



//======Тесты стеков==========================================
//Стек строк  |||||||||||||||| |||||||||||||||| |||||||||||||||| |||||||||||||||| |||||||||||||||| ||||||||||||||||
TEST (customStack, SpushIfFull)
{
	charStack testS(5);
	for (int i=0;i<5;i++)
	{
		testS.push("text");
	}
	ASSERT_ANY_THROW(testS.push("fail") );

}
TEST (customStack, SpopIfEmpty)
{
	charStack testS(1);
	ASSERT_ANY_THROW(testS.pop() );
}
TEST (customStack, createStackWithPositiveSize)
{
	ASSERT_NO_THROW(charStack testS(5) );
}
TEST (customStack, create_Stack_with_Negative_Size)
{
	ASSERT_ANY_THROW(charStack testS(-5) );
}
TEST (customStack, CheckWorking)
{
	charStack testS(2);
	EXPECT_EQ(true,testS.isEmpty() );
	EXPECT_NE(true,testS.isFull() );
	testS.push("1");
	EXPECT_NE(true,testS.isEmpty() );
	EXPECT_NE(true,testS.isFull() );
	testS.push("a");
	EXPECT_EQ(false,testS.isEmpty() );
	EXPECT_EQ(true,testS.isFull() );
	testS.pop();
	EXPECT_NE(true,testS.isEmpty() );
	EXPECT_NE(true,testS.isFull() );
	testS.pop();
	EXPECT_EQ(true,testS.isEmpty() );
	EXPECT_NE(true,testS.isFull() );
}
TEST (customStack, correctPushPops)
{
	charStack testS(2);
	testS.push("testing");
	string temp;
	temp=testS.pop();
	EXPECT_EQ("testing",temp);
}


//Стек чисел  |||||||||||||||| |||||||||||||||| |||||||||||||||| |||||||||||||||| |||||||||||||||| ||||||||||||||||
TEST (customFloatStack, SpushIfFull)
{
	floatResult testF(5);
	for (int i=0;i<5;i++)
	{
		testF.push(1.5);
	}
	ASSERT_ANY_THROW(testF.push(1.5) );

}
TEST (customFloatStack, SpopIfEmpty)
{
	floatResult testF(1);
	ASSERT_ANY_THROW(testF.pop() );
}
TEST (customFloatStack, createStackWithPositiveSize)
{
	ASSERT_NO_THROW(floatResult testF(5) );
}
TEST (customFloatStack, create_Stack_with_Negative_Size)
{
	ASSERT_ANY_THROW(floatResult testF(-5) );
}
TEST (customFloatStack, CheckWorking)
{
	floatResult testF(2);
	EXPECT_EQ(true,testF.isEmpty() );
	EXPECT_NE(true,testF.isFull() );
	testF.push(1.5);
	EXPECT_NE(true,testF.isEmpty() );
	EXPECT_NE(true,testF.isFull() );
	testF.push(2.6);
	EXPECT_EQ(false,testF.isEmpty() );
	EXPECT_EQ(true,testF.isFull() );
	testF.pop();
	EXPECT_NE(true,testF.isEmpty() );
	EXPECT_NE(true,testF.isFull() );
	testF.pop();
	EXPECT_EQ(true,testF.isEmpty() );
	EXPECT_NE(true,testF.isFull() );
}
TEST (customFloatStack, correctPushPops)
{
	floatResult testF(4);
	testF.push(3);
	float temp;
	temp=testF.pop();
	EXPECT_EQ(3,temp);
}


//======Тесты на приоритеты операторов=========================================
TEST(operatorPriority,correctPriority)
{
	int temp;
	temp=getPriority('+');
	EXPECT_EQ(1,temp);
	temp=getPriority('-');
	EXPECT_EQ(1,temp);
	temp=getPriority('*');
	EXPECT_EQ(2,temp);
	temp=getPriority('/');
	EXPECT_EQ(2,temp);
}