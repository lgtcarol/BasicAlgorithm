#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int c[101][101];

//СQ�ĸ赥
//��ԥ��c[i][0]���������1����0,��������������Ŀ
//bug: ������߼�˳�����⣺��ɵø赥���ȴﵽK�����������⣬�����ۼӵ�sum��ȥ
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
