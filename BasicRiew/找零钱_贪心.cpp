#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    int MoneyClass[6] = {100,50,20,10,5,1};            //记录钱的面值
    int MoneyIndex [6] ={0};                           //记录每种面值的数量
    int MoneyAll,MoneyCount = 0,cnt=0;//待兑换,当前兑换,总张数

    cout << "please enter the all money you want to exchange:" << endl;
    cin>>MoneyAll;

    //贪心法换钱
    for(int i = 0; i < 6;)
    {
        if(MoneyCount+MoneyClass[i] > MoneyAll) //太大了本面值,跳过！
        {
            i++;
            continue;
        }
        //本面值可以考虑
        MoneyCount += MoneyClass[i];
        ++MoneyIndex[i];//本面值的张数再增一
        ++cnt; //总张数增一
        if(MoneyCount == MoneyAll)
            break;
    }
    for(int i=0;i<6;++i)                                  //控制输出的循环
    {
        if(MoneyIndex[i] !=0 )
        {
            switch(i)
            {
            case 0:
                cout<<"the 100 have:"<<MoneyIndex[i]<<endl;
                break;
            case 1:
                cout<<"the 50 have:"<<MoneyIndex[i]<<endl;
                break;
            case 2:
                cout<<"the 20 have:"<<MoneyIndex[i]<<endl;
                break;
            case 3:
                cout<<"the 10 have:"<<MoneyIndex[i]<<endl;
                break;
            case 4:
                cout<<"the 5 have:"<<MoneyIndex[i]<<endl;
                break;
            case 5:
                cout<<"the 1 have:"<<MoneyIndex[i]<<endl;
                break;
            }
        }

    }
    cout<<"the total money have:"<<cnt<<endl;
    //system("pause");
    return 0;
}
