//一些变量的使用 
#include <cstdio>
#include<iostream> 
using namespace std;
int main(void){
	bool flag = -2; //把所有非零值解释为true 
	bool flag2 = 0;
	cout << flag << ' ' << flag2 << endl;
	
	const int a = 9999; //用const实现define方式的常量定义
	
	//超好用的string类
	string s;
	string s2 = s;
	string s3 = s + s2; //拼接可以直接用+号
	string s4;
	cin >> s4;
	cout << s4;
	
	string s0;
	getline(cin, s0); //输入有空格的字符串时
	cout << s0.length(); 
	
	string s6 = s0.substr(4);
	string s7 = s0.substr(5,3); //截取子串 
	cout << "截取字串的结果：" << s6 << ',' << s7 << endl;
	 
	
	 
	 
	return 0;
} 
