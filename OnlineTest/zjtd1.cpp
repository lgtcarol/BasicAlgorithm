#include <cstdio>
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
struct pos{
    int r;
    int l;
};
bool find2(vector<vector<int> > arr, vector<pos> &q)
{
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[0].size(); j++)
    {
        if(arr[i][j] == 2)
        {
            pos t;
            t.r = i;
            t.l = j;
            q.push_back(t);
        }
    }
    if(q.size()==0)
        return false;
    else
        return true;
}
bool correct(pos s, int row, int col)
{
    if(s.r >= 0 && s.r<row && s.l>=0 && s.l<col)
        return true;
    else
        return false;
}
void change(vector<vector<int> > &arr, vector<pos> &q1,vector<pos> &q2)
{
    int len = q1.size();
    pos s,x,z,y;
    for(int i = 0; i < len; i++)
    {
        pos t = q1[i];
        s.r = t.r-1;
        s.l = t.l;
        x.r = t.r+1;
        x.l = t.l;
        z.r = t.r;
        z.l = t.l-1;
        y.r = t.r;
        y.l = t.l+1;
        if(correct(s,arr.size(), arr[0].size()) && arr[s.r][s.l] == 1)
        {
            arr[s.r][s.l] = 2;
            q2.push_back(s);
        }

        if(correct(x,arr.size(), arr[0].size()) && arr[x.r][x.l] == 1)
        {
             arr[x.r][x.l] = 2;
             q2.push_back(x);
        }

        if(correct(z,arr.size(), arr[0].size()) && arr[z.r][z.l] == 1)
        {
             arr[z.r][z.l] = 2;
             q2.push_back(z);
        }

        if(correct(y,arr.size(), arr[0].size()) && arr[y.r][y.l]==1)
        {
            arr[y.r][y.l] = 2;
            q2.push_back(y);
        }

    }
}
int main()
{
    string sin;
    int res;
    vector<vector<int> > arr;
    while(getline(cin, sin))
    {
        if(sin.size() == 0)
            break;
        vector<int> t;
        my_split(sin, t);
        arr.push_back(t);
    }
    int row = arr.size();
    int col = arr[0].size();
    vector<pos> q1;
    vector<pos> q2;
    int cnt = 0;
    if(find2(arr,q1))
    {
        while(1)
        {
            cnt++; //第一次转换
            if(cnt%2)//从q1-->q2
            {
                change(arr,q1,q2);
                if(q2.size() == 0)
                    break;
                else
                    q1.resize(0);//清空另一个
            }
            else
            {
                change(arr,q2,q1);
                if(q1.size() == 0)
                    break;
                else
                    q2.resize(0);
            }

        }
    }
    else
        res = -1;
    bool flag = false;
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 1)
            {
                flag = true;
                break;
            }
        }
    if(flag)
        res = -1;
    else
        res = cnt-1;
    cout << res << endl;
    return 0;
}

