#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
//part1 : auto������ 
	auto x = 100;
	auto y = 1.5; //auto��ʵӦ���ǣ����泤���ĵ��������� 

//part2 : ���ڷ�Χ��forѭ��	
	int arr[4] = {0, 1, 2, 3};
	for(int &i : arr) //iΪ���ñ���
		i = i*2;
	for(int i : arr)
		cout << i << endl;
		
	vector<int> v(10);
	for(auto i : v)
		cout << i << " ";
	cout << endl;

//part3 : to_string
//���ǰ�?һ�� int �ͱ���������?һ������ת�� Ϊ string ���͵ı�����

	string s1 = to_string(123); //תintΪstr 
	cout << s1 << endl;
	string s2 = to_string(4.5); //float
	cout << s2 << endl;
	cout << s1+s2 << endl;
	printf("%s\n", (s1+s2).c_str()); //��printf���strin,���.c_str() 
	
//part4 : stoi, stod
//�� stoi �� stod ���Խ��ַ����� string ת��Ϊ��Ӧ�� int �͡� double �ͱ�
	string str = "123";
	int a = stoi(str);
	cout << a;
	str = "123.44";
	double b = stod(str);
	cout << b;

	return 0;
}
