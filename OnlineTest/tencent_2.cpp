#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int t = 0;
    for(int i = 0; i < n; i++)
    {
         cin >> t;
         arr.push_back(t);
    }
    int len = arr.size();

    vector<int> dp(len, 0);
////˼·һ����ÿ������֮ǰ�Ĺ����ϵ������˫ѭ��
//    for(int i = 1; i < len; i++)
//    {
//        dp[i] = dp[i-1];
//        if(arr[i] < 0) //�����ɹ�
//            for(int j = 0; j < i; j++)
//            {
//                if(arr[j] > 0) //�����ǰ��
//                {
//                    if(abs(arr[i]) > arr[j])
//                    {
//                        dp[i] += (i-j)*arr[j];
//                        arr[i] = arr[i] + arr[j];
//                        arr[j] = 0;
//
//                      //  cout << arr[i] << endl;
//                    }
//                    else if(abs(arr[i]) <= arr[j])
//                    {
//                        dp[i] += abs(arr[i])*(i-j);
//                        arr[j] = arr[j]+arr[i];
//                        arr[i] = 0;
//                        break;
//                    }
//                    else
//                        continue;
//                }
//            }
//        else if(arr[i] > 0 ) //�����ɱ���
//        {
//            for(int j  = 0; j < i; j++)
//            {
//                if(arr[j] < 0)
//                {
//                    int cha = abs(arr[j])-arr[i];
//                    if(cha <= 0)
//                    {
//                        dp[i] += (i-j)*abs(arr[j]);
//                        arr[i] += abs(arr[j]);//��С
//                        arr[j] = 0;
//                    }
//                    else if(cha >= 0)
//                    {
//                        dp[i] += (i-j)*arr[i];
//                        arr[i] = 0;
//                        arr[j] = arr[j] + arr[i];
//                        break;
//                    }
//                    else
//                        continue;
//                }
//
//            }
//        }
//        else
//            continue;
//    }
//˼·���������Ϊ0��ʾ��취�ۼӵõ�����Ҫ�Ľ��
    int sum = 0;
    int sign;
    if(arr[0] > 0)
        sign = 0;//0��
    else
        sign = 1;
    for(int i = 0; i < arr.size()-1; i++)
    {
        sum += abs(arr[i]);
        arr[i+1] = arr[i] + arr[i+1];

    }

    cout << sum << endl;
    return 0;
}
