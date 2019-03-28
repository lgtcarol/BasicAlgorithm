#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char c;
	cin >> c;
	if(isalpha(c)) //判断字母 
		cout << "c is alpha" << endl;
//	if(isalnum(c))  判断字母或数字 
//		cout << "c is num";	 
	if(islower(c))
		cout << (char)toupper(c); //转为大写后需强转为char 
	return 0;
}
