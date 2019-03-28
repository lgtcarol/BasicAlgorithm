#include <vector>
#include <iostream>
using namespace std;
class Solution {
	int b[2*100000]; //未知data长度情况下的辅助变量 
	int cnt = 0;
public:
	Solution():cnt(0)
	{
		for(int i = 0; i < 2*100000; i++)
			b[i] = 0;
	}
    int InversePairs(vector<int> data) {
        sort(data, 0, data.size()-1);
        return  cnt%1000000007;
    }
    void sort(vector<int> &a, int l, int h)
	{
		if(l < h)
		{
			int mid = (l+h)/2; //二路归并从中间划分
			sort(a, l, mid);
			sort(a, mid+1, h);
			merge(a, l, mid, h); 
		}
	}
	void merge(vector<int> &a, int l, int m, int h)
	{
	int i, j, k; //改为copy尝试 
	for(k = l; k <= h; k++)
		b[k] = a[k];
//	copy(a.begin()+l, a.begin()+h, b.begin()+l);
	for(i=m, j=h, k=h; i>=l && j>m && k>=l; k--)
	{
		if(b[i] > b[j])
		{
			cnt += j-m;
			a[k] = b[i--];
		}
		else
		{
			a[k] = b[j--];	
		}
	}
	while(i >= l)
		a[k--] = b[i--];
	while(j > m)
		a[k--] = b[j--];
	}
};
int main(void)
{
	vector<int> arr = {1,2,3,4,5,6,7,0};
	cout << arr.size() << endl;
	Solution T;
	cout << T.InversePairs(arr) << endl;
	return 0;	
} 

