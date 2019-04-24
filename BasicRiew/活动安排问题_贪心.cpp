#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
struct event{ //���Ϣ�ṹ
    int start;
    int endt;
    int id;
};
void GreedyChoose(int len, event a[], bool *flag);
//�����ع�:������Ϊ�����������ô����ˣ���һά�����Ӧһάָ�룬�����vector�鷳�ĵط������ڳ�����Ҫ��Ϊ������֪
void GreedyChoose(int len, event a[], bool *flag) //��Ϊ�õ�����������Ҫ���ݳ��Ȳ���
{
    int lastE = 0;
    flag[0] = true; //�����һ���¼�����������
    //int j = 0;
    cout << "in  greedy\n";
    for(int i = 1; i < len; i++)
    {
        if(a[i].start >= a[lastE].endt)
        {
            flag[i] = true;
            lastE = i;
            cout << "chosed: " << i << endl;
        }
    }
}
//bool cmp(event &a, event &b) //��ʼʱ����������(����)
//{
//    if(a.start < b.start)
//        return true;
//    else
//        return (a.endt < b.endt)?true:false;
//}
bool cmp(event &a, event &b)
{
    if(a.endt < b.endt)
        return true;
    else
        return false;
}
int main(int argc, char* argv[])
{
    int s[11] ={1,3,0,5,3,5,6,8,8,2,12};
    int f[11] ={4,5,6,7,8,9,10,11,12,13,14};
    event arr[11];
    for(int i = 0; i < 11; i++)
    {
        arr[i].start = s[i];
        arr[i].endt = f[i];
        arr[i].id = i;
    }
    //��һ��������
    sort(arr, arr+11, cmp);
    bool mark[11];
    memset(mark, false, sizeof(bool)*11);
    //�ڶ�����̰�İ���
    GreedyChoose(11,arr,mark);
    for(int i=0;i<11;i++)
        if(mark[i])
        {
            cout<<arr[i].id<<" "; //debug����ע������ʱʹ�õ���i,����mark[i]��ֱ�۶��ܿ���mark[i]��0��1��
        }

    return 0;
}


