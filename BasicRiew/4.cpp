#include <iostream>
using namespace std;

void func(int &a) //���βδ���&�������ԭ���������޸� 
{
	a = 99;
}
int main(void)
{
	struct stu
	{
		int grade;
		float score;
	}; 					 //�ṹ�嶨��û���𣬽������ڶ������ʱʡȥstruct
	struct stu arr1[10]; //��������Զ���ʼ����
	stu arr2[10] = {{0,1},{0,2}}; //��0��1����0��2����0��0��.����
	
	int n = 0;
	func(n);
	cout << n;


}







































