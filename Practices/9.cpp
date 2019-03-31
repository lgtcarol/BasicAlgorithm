#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
	void lgt_itoa(int x, string &a, int dec)
	{
		int cnt = 0;
		while(x > 0)
		{
			int d = x%dec;
			cout << d << endl;
			a.push_back(d+'0');
			x /= 10;
		}
		cout << "×ª»»ºóµÄ×Ö´®£º" << endl;
	//	a[cnt] = '\0';
	}
	
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;
       // string s;
        //char s[21];
        string s;
        lgt_itoa(x, s, 10);
        cout << s << endl;
        int len = s.length();
        cout <<  "len = " << len << endl;
        for(int i = 0; i < len/2; i++)
        {
        	if(s[i] != s[len-1-i])
        		return false;
		}

        return true;
    }
};
int main(void)
{
	Solution T;
	cout << T.isPalindrome(10);
	return 0;
}
