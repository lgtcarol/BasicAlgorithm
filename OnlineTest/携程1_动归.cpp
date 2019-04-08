#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
void my_split(string s)
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
int min_sum(int s, int e)
{
    int res = INT_MAX;
    vector<int> dp(arr.size(),0);
    dp[0] = arr[s];
    res = dp[0];
    for(int i = s+1; i <= e; i++)
    {
        if(dp[i-1] < 0)
        {
            dp[i] = dp[i-1]+arr[i];
        }
        else
            dp[i] = arr[i];
        if(res > dp[i])
            res = dp[i];
    }

    return res;
}
int main ()
{
    string s;
    cin>>s;
    my_split(s);
    vector<int> sum;
    for(int i = 1; i < arr.size()-1; i++)
    {
        int s1 = min_sum(0, i);
        int s2 = min_sum(i+1, arr.size()-1);
        int s = s1+s2;
        sum.push_back(s);
    }
    cout << sum.size() << endl;

    int m = INT_MAX;
    for(int i = 0; i < sum.size(); i++)
        if(m > sum[i])
            m = sum[i];
    cout << m << endl;
    return 0;
}
