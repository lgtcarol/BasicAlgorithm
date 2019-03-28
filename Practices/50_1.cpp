#include <vector>
#include <iostream>
using namespace std;
/**
˼·�ܼ򵥣�����������ĸ��
char���͹�256��ȡֵ�� 
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //��һ������¼�±�
		//һ�Σ�o��Ϊ����һ��Ϊ���������ٸ�
		if(str.length() <= 0)
			return -1;
		vector<int> book(256, -1);
		for(int i = 0; i < str.length(); i++)
		{
			
			int id = (int)str[i];
//			if(islower(str[i])) //AB...ab�Ĺ�ϣ�� 
//				id = str[i]-'A' ;
//			else
//				id = str[i]-'a' + 26;
			if(book[id] == -1)
				book[id] = i;
			else if(book[id] >= 0)
				book[id] = -2;
			else
				continue;
		} 
		int firstIndex = str.length();
		for(int i = 0; i < 256; i++)
		{
			if(book[i] < 0)
				continue;
			if(book[i] < firstIndex)
				firstIndex = book[i];
		}
		if(firstIndex < str.length())
			return firstIndex;
		else
			return -1;
    }
};
int main(void)
{
	Solution T;
	cout << T.FirstNotRepeatingChar("fsd dfd") << endl;
	return 0;	
} 
