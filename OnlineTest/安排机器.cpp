#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
//了解模板类
//hhh，画蛇添足了，因为machine和job的结构一样不必要区分。
//按两个关键字依次排序有点类似两次贪心
// cmp中 > 返回true,即为目标顺序
struct ma{
    int z;
    int w;
};
struct ta{
    int x;
    int y;
};
bool cmp1(ma &a, ma &b)
{
    if(a.z == b.z )
        return a.w > b.w;
    else
        return a.z > b.z;
}
bool cmp2(ta &a, ta &b)
{
    if(a.x == b.x )
        return a.y > b.y;
    else
        return a.x > b.x;
}
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<ma> mach;
    vector<ta> task;
    for(int i = 0; i < n; i++)
    {
        ma t;
        cin >> t.z >> t.w;
        mach.push_back(t);
    }
    for(int i = 0; i < m; i++)
    {
        ta t;
        cin >> t.x >> t.y;
        task.push_back(t);
    }
    sort(mach.begin(), mach.end(), cmp1);
    sort(task.begin(), task.end(), cmp2);
    vector<ta> res;
    int cnt = 0;
    for(int i = 0; i < task.size(); i++)
    {
        if(mach[cnt].z >= task[i].x)
        {
            if(mach[cnt].w >= task[i].y)
            {
                res.push_back(task[i]);
                cnt++;
            }
        }
    }
    cout << res.size()<< ' '<< endl;
    long sum = 0;
    for(int i = 0; i < res.size(); i++)
    {
  //      cout << res[i].x<< endl;
        sum += res[i].x*200+res[i].y*3;
    }
    cout << sum << endl;
    return 0;
}
