#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char c;
	cin >> c;
	if(isalpha(c)) //�ж���ĸ 
		cout << "c is alpha" << endl;
//	if(isalnum(c))  �ж���ĸ������ 
//		cout << "c is num";	 
	if(islower(c))
		cout << (char)toupper(c); //תΪ��д����ǿתΪchar 
	return 0;
}
