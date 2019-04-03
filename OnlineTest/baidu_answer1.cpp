#include <string>
#include <iostream>
#include <set>

using namespace std;
const int maxn = 3e6+5;
int Next[maxn];

//void getNext(string s)
//{
//    int m = s.length();
//    Next[0] = -1;
//    int j = 0;
//    int k = -1;
//    while( j < m) {
//        if (k == -1 || s[j] == s[k])
//            Next[++j] = ++k;
//        else
//            k = Next[k];
//    }
//}


int main()
{
    string s;
    cin >> s;
    set<string> uniq;
    string ns = s;
    for(unsigned int i = 0; i < s.length(); i++)
    {
        ns = ns.substr(1, s.length()-1);
        char ch = s[i];
        ns = ns+ch;
        uniq.insert(ns);
    }
    cout << uniq.size() << endl;
    return 0;
}

