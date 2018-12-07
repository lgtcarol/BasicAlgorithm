// ������44������������ĳһλ������
// ��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
// �������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
// ������������λ��Ӧ�����֡�

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/**
(1) ���������мɼ�����ɣ��𲽷ֽ�ȷ��˼·��ܣ��𲿷�����Ͼ���ʵ����
(2) ˼άͻ�ƣ�Ҫ�Ȳ»�˼����ʵ��ʲô���ܣ�����˼·���code.
              ������У����Լ�����˼·����������̡�
			  ��ͷ�ٿ����ܷ��� ��code ��˼ά�������棬�����Ǹ���ݵİ汾��
    ���ڵ�֪����ȷ��index��Ӧ��ֵʱ��������˱��ĳ���ⷨ��
(3) �������г���" ���� "ʱ��Ҫ���ǲ�ֵ��Χ�������� n-1=0ʱΪ0λ�����ɲ���pow(10,0)�������ģ�Ҫ��������
(4) ˼ά���У�����5λ������2�͵�3ָ��ͬһλ����񱾾Ͷ�����һ������������������ʹ�ͬʱ�����ȡ��������ÿλ�����ʺϵ�ȡ(���ÿ�������λ��) 
(5) Ҫ�󣺿�����У�˼·Ҫ�ᣬ���Լ�������ȥ����ϰ 
*/ 


int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if(index < 0)
		return -1;

	int digits = 1;
	while(true)
	{
		int numbers = countOfIntegers(digits);
		if(index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}

	return -1;
}

int countOfIntegers(int digits)
{
	if(digits == 1)
		return 10;
	digits--;
	return 9*countOfIntegers(digits);
}

//�˺�����ʱ�е�࣬����˼·���ң����Լ������ٿ����˴��� 
int digitAtIndex(int index, int d)
{
	int num = beginNumber(d) + index/d;
	int indexFromRight = d  - 	index%d;
	for(int i = 1; i < indexFromRight; ++i)
		num /= 10;
	return num % 10;
	
}
int beginNumber(int digits)
{
	if(digits == 1)
		return 0;

	return pow(10, digits - 1);
}

// ====================���Դ���====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // ����99�����һλ��9
	test("Test6", 190, 1);  // ����100�ĵ�һλ��1
	test("Test7", 1000, 3); // ����370�ĵ�һλ��3
	test("Test8", 1001, 7); // ����370�ĵڶ�λ��7
	test("Test9", 1002, 0); // ����370�ĵ���λ��0
	return 0;
}
























































