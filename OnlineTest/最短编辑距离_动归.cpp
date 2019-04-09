#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**先不考虑转移方程中的那两个是删除还是插入*/
int min_of3(int x, int y, int z)
{
    if(x > y)
        x = y;
    return (z<x) ? z:x;
}
int minDistance(string word1, string word2)
{
    int i = 0, j = 0;
    int row = word1.length();
    int col = word2.length();
    int edit[row+1][col+1]; //注意：与字符串各位对比时，多了一行index=0的空间，故在字符串比对时要注意下标
    edit[0][0] = 0;
    for(j = 1; j <= col; j++)
    {
        edit[0][j] = j;
    }
    for(i = 1; i <= row; i++)
    {
        edit[i][0] = i;
    }
    bool flag = false;
    for(i = 1; i <= row; i++)
    for(i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
    {
        if(word1[i] == word2[j]) //注意：当相等时不需要编辑
            edit[i+1][j+1] = edit[i][j];
        else                     //不等时：才从三种中考虑一种情况
            edit[i+1][j+1] = min_of3(edit[i][j+1]+1, edit[i+1][j]+1, edit[i][j]+1);
    }
    return edit[row][col];
}

