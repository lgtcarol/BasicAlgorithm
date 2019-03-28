#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	for (int i = 0; i < 6; i++)
		s.push();
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();
	return 0;
}
