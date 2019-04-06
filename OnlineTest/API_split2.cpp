#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
void split_tostr(string s, vector<string> &arr)
{
    int len = s.length();
    int sp = 0;
    string tmp;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ')
        {
            tmp = s.substr(sp,i-sp);
            //arr[cnt++] = atoi(tmp.c_str());
            arr.push_back(tmp);
            sp = i+1;
        }
    }
    tmp = s.substr(sp, len-sp);
    arr.push_back(tmp);
}
