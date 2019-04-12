
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<double> arr;
    for(int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        arr.push_back(t);
    }
    bool flag = true;//轮数为奇数
    int cnt = 0;
    double sum = 1.0;
    double p1 = 0.0;//小明获得金额
    double p2 = 0.0;
    int i ;
    for(i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            p1 += sum*arr[i];  //小明获得数目
            if(p1>=1.0)
                break;
        }
        else
        {
             p2 += sum*arr[i];
             if(p2>=1.0)
             {
                 flag = false;//Hua 获得
                 break;
             }
        }

    }
    double pro = 1.0;
    if(flag && i<n)
    {
        pro = pow(0.5,i+1);
    }
    if(!flag && i < n)
    {
        pro = 1-pow(0.5, i+1);
    }


    int rescnt = 100-n;
    flag = true;
    if(i == n && n < 100)//需要重复
    {
        if(n%2)
        {
            for(i = 0; i < rescnt; i++)
            {
                if(i%2 == 0)
                {
                    p2 += sum*arr[i];  //小明获得数目
                    if(p2>=1.0)
                        break;
                }
                else
                {
                    p1 += sum*arr[i];
                    if(p1>=1.0)
                    {
                        flag = false;//Hua 获得
                        break;
                    }
                }

            }
        }
        else
        {
            for(i = 0; i < rescnt; i++)
            {
                if(i%2 == 0)
                {
                    p1 += sum*arr[i];  //小明获得数目
                    if(p1>=1.0)
                        break;
                }
                else
                {
                    p2 += sum*arr[i];
                    if(p2>=1.0)
                    {
                        flag = false;//Hua 获得
                        break;
                    }
                }

            }
        }
    }
    if(flag && i<rescnt)
    {
        pro *= pow(0.5,i+1);
    }
    if(!flag && i < rescnt)
    {
        pro *= 1-pow(0.5, i+1);
    }
    cout.precision(4);
    cout << fixed << pro << endl;
    return 0;
}
