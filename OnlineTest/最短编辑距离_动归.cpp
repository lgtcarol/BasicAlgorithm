#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**�Ȳ�����ת�Ʒ����е���������ɾ�����ǲ���*/
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
    int edit[row+1][col+1]; //ע�⣺���ַ�����λ�Ա�ʱ������һ��index=0�Ŀռ䣬�����ַ����ȶ�ʱҪע���±�
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
        if(word1[i] == word2[j]) //ע�⣺�����ʱ����Ҫ�༭
            edit[i+1][j+1] = edit[i][j];
        else                     //����ʱ���Ŵ������п���һ�����
            edit[i+1][j+1] = min_of3(edit[i][j+1]+1, edit[i+1][j]+1, edit[i][j]+1);
    }
    return edit[row][col];
}

