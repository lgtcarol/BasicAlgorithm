#include <iostream>
#include <vector>
#include <string>
using namespace std;
//动态规划,从后往前，并记录(子问题从后是可以确定初始值的)
int getTransCount(const string &numstr)
{
    int len = numstr.size();
    vector<int> dp(len);
    int cur = 0;
    for(int i = len-1; i >= 0; i--)
    {
        cur = 0;
        //f(i) = f(i + 1) + g(i,i + 1) * f(i + 2)
        //part1:
        if(i < len-1)
            cur = dp[i+1];
        else
            cur = 1; //子问题初始化
        //part2:
        if(i < len-1)
        {
            int sum = (numstr[i]-'0')*10+numstr[i+1]-'0';
            //g(i,i+1)=1的情况
            if(sum > 9 && sum < 26)
            {
                if(i < len-2)
                    cur += dp[i+2];
                else
                    cur += 1; //类似初始化（因初始化的子问题情况也是两种）
            }
        }
        //终于得到f(i)的状态
        dp[i] = cur;
    }

}
//获得数字的翻译组合
int getTransCount(int number)
{
    if (number < 0) {
        return 0;
    }
    string numstring = to_string(number);
    return getTransCount(numstring);
}

int main(void)
{
    cout << getTransCount(12258) << endl;
    return 0;
}
