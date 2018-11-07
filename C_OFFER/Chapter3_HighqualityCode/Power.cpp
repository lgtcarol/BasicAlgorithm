#include <iostream>
#include <cmath> 
//疑惑：unsigned int需要考虑适用场景吗 
//思考：不过既然已经限定一定为正数了，为什么用int那么浪费；可是Power中的exponent可能使得就算用usigned int也不见得比原先用int节省 
double PowerExponent(double base, int exponent);
bool equal(double x, double y);
bool g_InvalidInput = false;//有效性检查 
	
double Power(double base, int exponent)
{
	bool expNeg = false;
	printf("out:%d\t", exponent); 
	if(equal(base,0.0) && exponent<0)
	{
		printf("in: %d\n", exponent);
		g_InvalidInput = true;
		return 0.0; 
	} 
	if(exponent < 0)//若指数为负数，修正为正数参与计算 
	{
		exponent = -exponent;
		expNeg = true;
	}
	double result = PowerExponent(base, exponent);
	if(expNeg == true)
		result = 1.0/result;
	return result;
}
double PowerExponent(double base, int exponent)
{
	double result = 1.0;
	for(int i = 1; i <= exponent; i++)
		result *= base;
	return result; 
	//Notes:就一个返回值弄错排查半天！
	//反思：不要受限于课本答案，既然自己写就大胆理出自己的思路 
}

//从奇数偶数角度用递归实现
double PowerHalfExponent(double base, int exponent)
{
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;
	double result = PowerHalfExponent(base, exponent/2);
	if(exponent%2 == 1)
		result = base*result;
	return result;
}
 
//bool equal(double x, double y)
//{
//	if(fabs(x-y) < .1e6)
//		return true;
//	else
//		return false;
//}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}
