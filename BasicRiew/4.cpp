#include <iostream>
using namespace std;

void func(int &a) //在形参处加&，代表对原变量进行修改 
{
	a = 99;
}
int main(void)
{
	struct stu
	{
		int grade;
		float score;
	}; 					 //结构体定义没区别，仅仅是在定义变量时省去struct
	struct stu arr1[10]; //不会进行自动初始化的
	stu arr2[10] = {{0,1},{0,2}}; //（0，1）（0，2）（0，0）.。。
	
	int n = 0;
	func(n);
	cout << n;


}







































