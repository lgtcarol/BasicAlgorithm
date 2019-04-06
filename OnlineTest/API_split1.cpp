/**转换字符串为整数数组，分隔符为,*/
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
void my_split(string s, vector<int> &arr)
{
    int len = s.length();
    int sp = 0;
    string tmp;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ',')
        {
            tmp = s.substr(sp,i-sp);
            arr.push_back(atoi(tmp.c_str()));
            sp = i+1;
        }
    }
    tmp = s.substr(sp, len-sp);
    arr.push_back(atoi(tmp.c_str()));
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
    string sin;
    int arr[50]={0};
    int cnt = 0;
    getline(cin, sin);
    string s = sin.substr(1, sin.length()-2);
    int len = s.length();
    int sp = 0;
    string tmp;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ',')
        {
            tmp = s.substr(sp,i-sp);
            arr[cnt++] = atoi(tmp.c_str());
            sp = i+1;
        }
    }
    tmp = s.substr(sp, len-sp);
    arr[cnt] = atoi(tmp.c_str());
    for(int i = 0; i < 50; i++)
    {
        if(arr[i] == 0)
            break;
        cout << arr[i] << ',' ;
    }
    cout << endl;
    return 0;
}

