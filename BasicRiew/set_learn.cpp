#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	cout << *(s.begin()) << endl;
	
	for(int i = 0; i < 6; i++)
		s.insert(i); //集合插入元素
	
	for(auto it = s.begin(); it != s.end(); it++) //遍历 
		cout << *it << " ";
	
	s.erase(2); //将某元素删除 
	cout << endl << (s.find(2) != s.end()) << endl; //能否找到该元素 
	
	s.erase(1);
	cout << (s.find(1) != s.end()) << endl;  
	return 0;
} 
