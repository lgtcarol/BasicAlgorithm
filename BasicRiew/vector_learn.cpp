#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> a;
	cout << a.size() << endl;
	for(int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	
	cout << a.size() << endl;
	vector<int> b(15);
	cout << a.size() << endl;
	
	for(int i = 0; i < b.size(); i++)
	{
		b[i] = 15;
	}
	for(int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
	cout << endl;
	
	vector<int> c(20, 2);
	for (int i = 0; i < c.size(); i++ )
		cout << c[i] << ' ';
	cout << endl;
	
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++) //使用迭代器遍历(vector<int>::iterator可以用auto代替)  
		cout << *it << ' '; //迭代器在用值得时候加*号 
}
