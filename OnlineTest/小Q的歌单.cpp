#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int c[101][101];

//小Q的歌单
//犹豫：c[i][0]的组合数是1不是0,杨辉三角求组合数目
//bug: 题意得逻辑顺畅问题：组成得歌单长度达到K才算满足题意，才能累加到sum中去
void combinenum(void)
{
    for(int i=0; i <= 100; i++ )
    {
        c[i][0] = 1;
        //c[i][1] = 1;
        c[i][i] = 1;
    }
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 1; j < i; j++)
        {
            c[i][j] = c[i-1][j-1]+c[i-1][j];

        }
    }
}
int main(void)
{
    int K, A, X, B, Y;
    cin >> K >> A >> X >> B >> Y;
    long long  spec = 0;
    long long sum = 0;
    combinenum();
    for(int i = 0; i <= X; i++)
    {
        spec = c[X][i];
        if(i*A <= K && (K-i*A)%B == 0 && (K-i*A)/B <= Y)
        {
            int y = (K-i*A)/B;
            if(i*A + y*B == K)
            {
                spec = spec * c[Y][(K-i*A)/B];
                sum += spec;
            }
        }

    }
    cout << sum%1000000007 << endl;

    return 0;
}
