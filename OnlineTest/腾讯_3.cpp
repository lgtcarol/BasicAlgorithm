#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int minx = arr[0];
    cout << minx << endl;
    for(k-=1; k>0; k--)
    {
       for(int i = 0; i < arr.size(); i++)
       {
            if(arr[i] != 0)
                arr[i] -= minx;
            else
                continue;
       }
       bool flag = false;
       int i;
       for(i = 0; i < arr.size(); i++)
       {
           if(arr[i] > 0)
           {
               flag = true;
               break;
           }
       }
       if(flag)
            cout << arr[i] << endl;
       else
            cout << 0 << endl;
    }
    return 0;
}
