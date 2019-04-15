#include <iostream>
#include<stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int test(int a, int b)
{
    //int dp[][] = new int[a][b];
    vector<vector<int> > dp;
    dp.resize(a);
    for(int i = 0; i < a; i++)
    {
        dp[i].resize(b);
    }
    for (int i = 0; i < a; i++)
        dp[i][0] = 1;
    for (int i = 0; i < b; i++)
        dp[0][i] = 1;
    for (int i = 1; i < a; i++)
        for (int j = 1; j < b; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[a - 1][b - 1];
}


int main()
{
    int n;
    vector<int> arr;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int u;
        scanf("%d",&u);
        arr.push_back(u);
    }
    int result = 1;
    int p = 0;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && i == 0)
        {
            arr[i] = arr[1];
            continue;
        }

        if (arr[i] == 0 && i == 1)
        {
            arr[i] = arr[0];
            continue;
        }

        if (arr[i] == 0 && arr[i - 1] != 0)
            p = i;

        if (arr[i] == 0 && arr[i + 1] != 0)
        {
            q = i;
            result *= test(q - p + 2, arr[p - 1] - arr[q + 1] + 1);
        }
    }

    printf("%d\n",result);
    return 0;
}

