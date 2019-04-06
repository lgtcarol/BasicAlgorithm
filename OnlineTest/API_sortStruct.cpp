#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct tt{
    int x;
    char y;
};
bool cmp(tt &a, tt &b)
{
    return a.x<b.y;
}
int main()
{
    vector<tt> a;
    for(int i = 0; i < 2; i++)
    {
        tt tmp;
        tmp.x = 3-i;
        tmp.y = 'a'+i;
      a.push_back(tmp);
    }// ³õÊ¼£º3 2
    sort(a.begin(), a.end(), cmp);
    cout << a[0].x << endl;
    cout << a[1].x << endl;
    //ÅÅºó£º2 3
}

