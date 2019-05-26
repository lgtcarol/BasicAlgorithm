#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
//最长公共子串
int LCS_length(const string &str1, const string &str2, vector<vector<int> > &veca)
{
    int i, j;
    int biggest = 0;
    if (str1 == "" || str2 == "")
        return 0;
    for(i = 0; i <= str1.length(); i++)
        veca[i].resize(str2.length()+1, 0);
    for(j = 0; j <= str2.length(); j++)
        veca[0][j] = 0;
    for(i = 1; i <= str1.length(); i++)
        for(j = 1; j <= str2.length(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                veca[i][j] = veca[i-1][j-1]+1;
                if(veca[i][j] > biggest)
                    biggest = veca[i][j];
            }
            else
            {
                veca[i][j] = 0;
            }
        }
    return biggest;
}
int main()
{
    string input;
    getline(cin, input);
    stringstream ss(input);
    string str1;
    ss >> str1;
    string str2;
    ss >> str2;
    vector<vector<int> > veca(str1.length() + 1);
    cout << LCS_length(str1, str2, veca) << endl;
    return 0;
}


//最长公共子序列
//二维数组veca记录的是两个字符串Xi和Yj的LCS长度
int LCS_length(const string &str1, const string &str2, vector<vector<int> > &veca) {
	int i, j;
	int biggest = 0;
	if (str1 == "" || str2 == "")
		return 0;

	for (i = 0; i <= str1.length(); i++) {
		veca[i][0] = 0;
	}
	for (j = 0; j <= str2.length(); j++) {
		veca[0][j] = 0;
	}
	for (i = 1; i <= str1.length(); i++) {
		for (j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				veca[i][j] = veca[i - 1][j - 1] + 1;
			}
			else {
				if (veca[i - 1][j] >= veca[i][j - 1])
					veca[i][j] = veca[i - 1][j];
				else
					veca[i][j] = veca[i][j-1];
			}
		}
	}
	return veca[str1.length()][str2.length()];
}

//int main() {
//	string input;
//	getline(cin, input);
//        stringstream ss(input);
//        string str1, str2;
//	ss >> str1;
//	ss >> str2;
//	//将veca初始化为一个二维数组,其行列值分别为str1和str2的长度加1
//	//二维数组veca记录的是两个字符串Xi和Yj的LCS长度
//	vector<vector<int> > veca(str1.length() + 1, vector<int>(str2.length() + 1));
//	cout << LCS_length(str1, str2, veca) << endl;
//	return 0;
//}
