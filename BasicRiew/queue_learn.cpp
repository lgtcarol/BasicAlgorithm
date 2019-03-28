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
	q.pop(); //注意尽管是Pop,但移除得是队首元素 
	cout << q.front() << endl;
	return 0;
}
