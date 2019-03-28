#include<iostream>
#include<cstring >
#include<algorithm>
using namespace std;
int main()
{
    string a[4];
    for(int i=0;i<4;i++)
        getline(cin,a[i]);
    sort(a,a+4);
    for(int i=0;i<4;i++)
        cout<<a[i]<<endl;
    return 0;
}
