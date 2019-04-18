#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
void my_split(string s, vector<int> &arr)
{
    int len = s.length();
    int sp = 0;
    string tmp;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ')
        {
            tmp = s.substr(sp,i-sp);
            arr.push_back(atoi(tmp.c_str()));
            sp = i+1;
        }
    }
    tmp = s.substr(sp, len-sp);
    arr.push_back(atoi(tmp.c_str()));
}
int main()
{
    int n;
    int res;
    string sin;
    vector<vector<int> > arr;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, sin);
        vector<int> t;
        my_split(sin, t);
        arr.push_back(t);
    }
    int row = arr.size();
    int col = arr[0].size();
    cout << row << ' ' << col << endl;

    return 0;
}
/**
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
*/

