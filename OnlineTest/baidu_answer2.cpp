
#include <string>
#include <iostream>
#include <vector>

using namespace std;
////思路一：子串
//int numPrint(string sub, string tar)
//{
//    string tmp(sub);
//    int len = tar.length();
//    int cnt = 0;
//
//    while(tmp.length() > 0)
//    {
//        int pos = tmp.find(tar);
//      //  if(pos < sub.length()) //找到子串需要移动从后面
//        if(pos != -1)
//        {
//            cnt++;
//          //  if(pos+len < sub.length())//还有串
//            tmp = tmp.substr(pos+len);
//        }
//        else
//            break;
//    }
//  //  cout << "func_cnt: " << cnt << endl;
//    return cnt;
//}
//思路二：改变起始位置
int numPrint(string sub, string tar)
{
    int beg = 0;
    string tmp = sub;
    int len = tar.length();
    int cnt = 0;
    while(beg < sub.length())
    {
        int pos = tmp.find(tar,beg);
        if(pos != -1)
        {
            beg = pos + len;
            cnt ++;
        }
        else
            break;
    }
    return cnt;
}
int main()
{
    string A;
    string B;
    int Q;
    cin >> A;
    cin >> B;
    cin >> Q;
    vector<int> a;
    for(int i = 0; i < Q; i ++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        a.push_back(y); //0-(2n-1)
    }
    string sub = "";
    for(int i = 0; i < a.size(); i+=2)
    {
        int ix = a[i]-1;
        int iy = a[i+1]-1;
        int len = iy-ix+1;
        sub = A.substr(ix, len);
        cout << "被查找串: " << sub << endl;
        int n = numPrint(sub, B);
        cout << n << endl;
    }
    return 0;
}
