#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;


int main()
{
    //����������˳���ź�˳���
    int s[10] = {2,3,4,5,6,7,8,9,10,11};
    int f[10] = {3,5,7,6,9,8,12,10,13,15};
    int tollen = (3-2);  //��Ȼѡ����һ��

    int lastE = 0;
    for(int i = 1; i < 10; i++)
    {
        if(s[i] >= s[lastE] && f[i] > f[lastE]) //�߶�Ϊ����ƴ�ӵ����
        {
            tollen += f[i]-f[lastE];
            lastE = i;
        }
        else if(s[i] > f[lastE]) //���ּ��,����s[0]�Ĳ���
        {
            tollen += f[i]-s[i];
            lastE = i;
        }
        else
            continue;
    }
//ԭ�㷨
//    for(int i=1,j=0; i<10; ++i)
//    {
//        if(s[i] >= f[j])
//        {
//            tollen += (f[i]-s[i]);
//            j = i;
//        }
//        else
//        {
//            if(f[i] <= f[j])
//                continue;
//            else
//            {
//                tollen += f[i] - f[j];
//                j = i;
//            }
//        }
//    }

    cout<<tollen<<endl;
    //system("pause");
    return 0;
}

