#include <iostream>
#include <cmath> 
//�ɻ�unsigned int��Ҫ�������ó����� 
//˼����������Ȼ�Ѿ��޶�һ��Ϊ�����ˣ�Ϊʲô��int��ô�˷ѣ�����Power�е�exponent����ʹ�þ�����usigned intҲ�����ñ�ԭ����int��ʡ 
double PowerExponent(double base, int exponent);
bool equal(double x, double y);
bool g_InvalidInput = false;//��Ч�Լ�� 
	
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
	if(exponent < 0)//��ָ��Ϊ����������Ϊ����������� 
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
	//Notes:��һ������ֵŪ���Ų���죡
	//��˼����Ҫ�����ڿα��𰸣���Ȼ�Լ�д�ʹ�����Լ���˼· 
}

//������ż���Ƕ��õݹ�ʵ��
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

// ====================���Դ���====================
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
    // ������ָ����Ϊ����
    Test("Test1", 2, 3, 8, false);

    // ����Ϊ������ָ��Ϊ����
    Test("Test2", -2, 3, -8, false);

    // ָ��Ϊ����
    Test("Test3", 2, -3, 0.125, false);

    // ָ��Ϊ0
    Test("Test4", 2, 0, 1, false);

    // ������ָ����Ϊ0
    Test("Test5", 0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test6", 0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test7", 0, -4, 0, true);

    return 0;
}
