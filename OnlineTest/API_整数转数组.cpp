#include<iostream>
#include<vector>
#include<algorithm>

void digit_break(int n, vector<int> &arr)
{
    while(n>0)
    {
        arr.push_back(n%10);
        n/=10;
    }
    reverse(arr.begin(), arr.end());
    //10203-->数组形式10203
}
