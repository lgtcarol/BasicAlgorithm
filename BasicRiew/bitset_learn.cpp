#include <iostream>
#include <bitset>
using namespace std; 
int main()
{
	bitset<5> b("001"); //1101->10110, 001->10000(将高位放右边，不够的低位补0)
	bitset<5> value(11); //11001, 二进制的高位放右边，不够低位补0 
	/**
	bitset<5> b;
	
	bitset<5> b(s);
	bitset<5> b(s,pos,n); 从str[pos]开始，n位长度 
	
	*/
	for (int i = 0; i < 5; i++)
		cout << value[i];
	cout << endl << b.any(); //有1？ 
	cout << endl << b.none(); //没1？ 
	cout << endl << b.count(); //1的个数 
	cout << endl << b.size(); //二进制位个数
	cout << endl << b.test(2); //测试下标为2处的二进制是否为1 
	
	b.set(4); //下标4处置1 
	b.reset();
	b.reset(3); //下标3处归零
	b.flip(); //所有二进制逐位取反
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << b[i];
		 
	unsigned long a = b.to_ulong(); //将b转为 unsigned long
	cout <<endl << a << endl;
	return 0;
} 
