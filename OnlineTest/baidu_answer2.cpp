
#include <string>
#include <iostream>
#include <vector>

using namespace std;
////˼·һ���Ӵ�
//int numPrint(string sub, string tar)
//{
//    string tmp(sub);
//    int len = tar.length();
//    int cnt = 0;
//
//    while(tmp.length() > 0)
//    {
//        int pos = tmp.find(tar);
//      //  if(pos < sub.length()) //�ҵ��Ӵ���Ҫ�ƶ��Ӻ���
//        if(pos != -1)
//        {
//            cnt++;
//          //  if(pos+len < sub.length())//���д�
//            tmp = tmp.substr(pos+len);
//        }
//        else
//            break;
//    }
//  //  cout << "func_cnt: " << cnt << endl;
//    return cnt;
//}
//˼·�����ı���ʼλ��
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
        cout << "�����Ҵ�: " << sub << endl;
        int n = numPrint(sub, B);
        cout << n << endl;
    }
    return 0;
}
