#include <cstring>
#include <iostream>
#include <set>
#include <string>

using namespace std;

const int maxn = 3e6+5;

int Next[maxn];

void getNext(string s)
{
    int m = s.length();
    Next[0] = -1;
    int j = 0;
    int k = -1;
    while( j < m) {
        if (k == -1 || s[j] == s[k])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}


int main()
{

    string s;
    cin >> s;
    memset(Next,0,sizeof(Next));
    int len = s.length();
    getNext(s);

    int ans = len - Next[len];
    //cout << Next[len] << endl;
    if (len%ans == 0)
        cout << ans << endl;
    else
        cout << len << endl;


    return 0;

}
