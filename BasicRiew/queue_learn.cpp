#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	for (int i = 0; i < 6; i++)
		q.push(i);
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;
	q.pop(); //ע�⾡����Pop,���Ƴ����Ƕ���Ԫ�� 
	cout << q.front() << endl;
	return 0;
}
