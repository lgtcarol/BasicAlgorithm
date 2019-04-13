#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void digit_break(int n, vector<int> &arr)
{
    while(n>0)
    {
        arr.push_back(n%10);
        n/=10;
    }
}
int main()
{
    int a;
    cin >> a;
    char han[] = {'L','S', 'B','Q','W'};
    if(a<0 || a>99999)
        return 0;
    if(a == 0)
    {
        cout << "L" << endl;
        return 0;
    }
    vector<int> arr_n;
    digit_break(a, arr_n);
    reverse(arr_n.begin(), arr_n.end());
    for(int i = 0; i < arr_n.size(); i++)
    {
        cout << arr_n[i]; //将该数转换为整数数组
    }
    cout << "check over!" << endl;
    int num = arr_n.size();
    string res = "";
    for(int i = 0; i<num-1; i++)
    {
    //首位定不是0
        if(arr_n[i] == 0)
            res += 'L';
        else{
            char c = arr_n[i]+'0';
            res += c;
            res += han[num-1-i];
        }
    }
    if(arr_n[num-1] == 0)
        res+= 'L';
    else
    {
        char c = arr_n[num-1]+'0';
        res += c;
    }

    cout << res << endl;
    return 0;
}
