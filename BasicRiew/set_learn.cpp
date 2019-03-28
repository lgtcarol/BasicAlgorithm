#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	cout << *(s.begin()) << endl;
	
	for(int i = 0; i < 6; i++)
		s.insert(i); //���ϲ���Ԫ��
	
	for(auto it = s.begin(); it != s.end(); it++) //���� 
		cout << *it << " ";
	
	s.erase(2); //��ĳԪ��ɾ�� 
	cout << endl << (s.find(2) != s.end()) << endl; //�ܷ��ҵ���Ԫ�� 
	
	s.erase(1);
	cout << (s.find(1) != s.end()) << endl;  
	return 0;
} 
