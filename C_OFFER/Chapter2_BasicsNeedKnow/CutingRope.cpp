#include <iostream>
#include <cmath>
using namespace std;

int maxProductAfterCutting_solution1(int length) 
{
	int n = length;
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	//���¶��ϻ�ý⣨��������ĳ�ʼ����ʵ���ǴӼ��ĽǶȣ����Ǵ�����������Ž⣩
	//����������±����������Ǿ���ṹ����ֻ�Ǽ�¼��ʽ�����飬���¶��ϵ�һ��ʵ�� 
	int *record= new int(length+1);//���0��ʼ���� 
	record[0] = 0;
	record[1] = 1;
	record[2] = 2;
	record[3] = 3;
	//��̬�滮����Ҫ�����������ţ��˴�ʱmax������Ϊ����̰���㷨��ÿ����֪��������ѡ�����
	//�ʶ��Ʊػ���úܶ��Ȼ����»������
	//�����������ظ����ֶ����ǲ������¶��ϵ�ʵ�ַ�ʽ 
	int max = 0;
	int sonProduct = 0; 
	for(int i = 4; i <= length; i++)
	{
		max = 0;
		//���¶��ϵ��ص���ǣ���Ҫ�ļ���֪���ص�����ô��
		//lgt:С�Ķ� 
		for(int j = 1; j <= i/2; j++)
		{
			sonProduct = record[j] * record[i-j];
			if(max < sonProduct)
				max = sonProduct; 
		} 
		record[i] = max;//������Ž� 
	} 
//	printf("The latest max is %d\n",max); 
	//Notes:�ǵ��޸��걣�氡 
	int maxProduct = max;
	delete []record;
	return maxProduct; 
}

int maxProductAfterCutting_solution2(int length)
{
	//Notes���������зֽ���˼·��Ϊ�η�����10���ڵ����ݾ�ok
	//,Ϊ�γ�ʼ��ֻ�����2��3 
	int n = length;
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	
	//���ܺ�3�Ͱ�3�֣��ֵ�4ʱ��2��
	int numsOf3 = length/3;
	if(length - 3*numsOf3 == 1)
		numsOf3 -= 1;
	int numsOf2 = (length-3*numsOf3)/2;
	return (int)(pow(3, numsOf3))*(int)(pow(2, numsOf2));
} 


// ====================���Դ���====================
void test(const char* testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}
