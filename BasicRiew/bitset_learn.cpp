#include <iostream>
#include <bitset>
using namespace std; 
int main()
{
	bitset<5> b("001"); //1101->10110, 001->10000(����λ���ұߣ������ĵ�λ��0)
	bitset<5> value(11); //11001, �����Ƶĸ�λ���ұߣ�������λ��0 
	/**
	bitset<5> b;
	
	bitset<5> b(s);
	bitset<5> b(s,pos,n); ��str[pos]��ʼ��nλ���� 
	
	*/
	for (int i = 0; i < 5; i++)
		cout << value[i];
	cout << endl << b.any(); //��1�� 
	cout << endl << b.none(); //û1�� 
	cout << endl << b.count(); //1�ĸ��� 
	cout << endl << b.size(); //������λ����
	cout << endl << b.test(2); //�����±�Ϊ2���Ķ������Ƿ�Ϊ1 
	
	b.set(4); //�±�4����1 
	b.reset();
	b.reset(3); //�±�3������
	b.flip(); //���ж�������λȡ��
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << b[i];
		 
	unsigned long a = b.to_ulong(); //��bתΪ unsigned long
	cout <<endl << a << endl;
	return 0;
} 
