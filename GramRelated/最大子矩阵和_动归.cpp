#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//要求一个二维矩阵的最大子矩阵，首先要会求一维矩阵的最大子矩阵（即一维数组连续最大和）
//假设原二维矩阵的最大子矩阵所在的行为i到j
//  1 当i = j时，则最大子矩阵为第i行的连续最大和
//  2 当i != j时，现在我们已经直到最大子矩阵的行，要求的是其所在的列
//      我们把从第i行到第j行的所有行相加，得到一个只有一行的一维数组，则该一维数组
//      的连续最大和就是最大子矩阵。

//求一维数组的连续最大和
int ConsequentMaxNum(vector<int> &arr)
{
    int len = arr.size();
    vector<int> dp(len);
    dp[0] = arr[0];
    int maxV = dp[0];
    for(int i = 1; i < len; i++)
    {
        if(dp[i-1] < 0)
            dp[i] = arr[i];
        else
            dp[i] = dp[i-1]+arr[i];
        if(maxV < dp[i])
            maxV = dp[i];
    }
    return maxV;
}

//把矩阵v的第i行到第j行进行合并，并求出连续最大和，N为矩阵v的列数
int MergeConsequentMaxNum(vector<vector<int> > &v, int i, int j, int N)
{
    vector<int> arr(N, 0);
    for(int row = i; row <= j; row++)
        for(int col = 0; col < N; col++)//枚举行内所有的列
            arr[col] += v[row][col];
    int ans = ConsequentMaxNum(arr);
    return ans;
}

int GetMaxSubMatrix(vector<vector<int> > &v, int N)
{
    int MAX = 0, temp;
    for(int i = 0; i < N; i++)//从第i行开始
        for(int j = i; j < N; j++) //到第j行结束
            if((temp = MergeConsequentMaxNum(v, i, j, N))>MAX)
                MAX = temp;
    return MAX;

}

int main()
{
    int N;
    cin>> N;
    vector<vector<int> > v(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> v[i][j];
    cout << GetMaxSubMatrix(v, N) << endl;

    return 0;
}
