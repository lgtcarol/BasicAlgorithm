#include <vector>
#include <iostream>
using namespace std;
/**
思路很简单，请审题是字母！
char类型共256种取值。 
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //第一个：记录下标
		//一次：o次为负，一次为正，两次再负
		if(str.length() <= 0)
			return -1;
		vector<int> book(256, -1);
		for(int i = 0; i < str.length(); i++)
		{
			
			int id = (int)str[i];
//			if(islower(str[i])) //AB...ab的哈希。 
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
