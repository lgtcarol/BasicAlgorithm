#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    int MoneyClass[6] = {100,50,20,10,5,1};            //��¼Ǯ����ֵ
    int MoneyIndex [6] ={0};                           //��¼ÿ����ֵ������
    int MoneyAll,MoneyCount = 0,cnt=0;//���һ�,��ǰ�һ�,������

    cout << "please enter the all money you want to exchange:" << endl;
    cin>>MoneyAll;

    //̰�ķ���Ǯ
    for(int i = 0; i < 6;)
    {
        if(MoneyCount+MoneyClass[i] > MoneyAll) //̫���˱���ֵ,������
        {
            i++;
            continue;
        }
        //����ֵ���Կ���
        MoneyCount += MoneyClass[i];
        ++MoneyIndex[i];//����ֵ����������һ
        ++cnt; //��������һ
        if(MoneyCount == MoneyAll)
            break;
    }
    for(int i=0;i<6;++i)                                  //���������ѭ��
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
