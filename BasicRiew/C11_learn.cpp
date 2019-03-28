#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
//part1 : auto的声明 
	auto x = 100;
	auto y = 1.5; //auto真实应用是：代替长串的迭代器声明 

//part2 : 基于范围的for循环	
	int arr[4] = {0, 1, 2, 3};
	for(int &i : arr) //i为引用变量
		i = i*2;
	for(int i : arr)
		cout << i << endl;
		
	vector<int> v(10);
	for(auto i : v)
		cout << i << " ";
	cout << endl;

//part3 : to_string
//就是把?一个 int 型变量量或者?一个数字转化 为 string 类型的变量量

	string s1 = to_string(123); //转int为str 
	cout << s1 << endl;
	string s2 = to_string(4.5); //float
	cout << s2 << endl;
	cout << s1+s2 << endl;
	printf("%s\n", (s1+s2).c_str()); //从printf输出strin,需加.c_str() 
	
//part4 : stoi, stod
//用 stoi 、 stod 可以将字符串串 string 转化为对应的 int 型、 double 型变
	string str = "123";
	int a = stoi(str);
	cout << a;
	str = "123.44";
	double b = stod(str);
	cout << b;

	return 0;
}
