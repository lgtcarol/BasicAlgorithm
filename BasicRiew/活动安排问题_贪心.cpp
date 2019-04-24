#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
struct event{ //活动信息结构
    int start;
    int endt;
    int id;
};
void GreedyChoose(int len, event a[], bool *flag);
//基础回顾:数组作为参数就是引用传递了，且一维数组对应一维指针，但相比vector麻烦的地方就在于长度需要作为参数告知
void GreedyChoose(int len, event a[], bool *flag) //因为用的数组所以需要传递长度参数
{
    int lastE = 0;
    flag[0] = true; //假设第一个事件被安排上了
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
//bool cmp(event &a, event &b) //起始时间升序排列(错误！)
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
    //第一步：排序
    sort(arr, arr+11, cmp);
    bool mark[11];
    memset(mark, false, sizeof(bool)*11);
    //第二步：贪心安排
    GreedyChoose(11,arr,mark);
    for(int i=0;i<11;i++)
        if(mark[i])
        {
            cout<<arr[i].id<<" "; //debug错误：注意索引时使用的是i,而非mark[i]（直观都能看到mark[i]非0即1）
        }

    return 0;
}


