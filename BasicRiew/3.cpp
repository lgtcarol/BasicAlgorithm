//һЩ������ʹ�� 
#include <cstdio>
#include<iostream> 
using namespace std;
int main(void){
	bool flag = -2; //�����з���ֵ����Ϊtrue 
	bool flag2 = 0;
	cout << flag << ' ' << flag2 << endl;
	
	const int a = 9999; //��constʵ��define��ʽ�ĳ�������
	
	//�����õ�string��
	string s;
	string s2 = s;
	string s3 = s + s2; //ƴ�ӿ���ֱ����+��
	string s4;
	cin >> s4;
	cout << s4;
	
	string s0;
	getline(cin, s0); //�����пո���ַ���ʱ
	cout << s0.length(); 
	
	string s6 = s0.substr(4);
	string s7 = s0.substr(5,3); //��ȡ�Ӵ� 
	cout << "��ȡ�ִ��Ľ����" << s6 << ',' << s7 << endl;
	 
	
	 
	 
	return 0;
} 
