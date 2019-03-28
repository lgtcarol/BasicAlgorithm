#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;
const int len = 10;
vector<int> b(len);
void merge(vector<int> &a, int l, int m, int h);
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
	for(i=l, j=m+1,k = l; i<=m && j<=h && k<=h; k++)
	{
		if(b[i] < b[j])
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while(i <= m)
		a[k++] = b[i++];
	while(j <= h)
		a[k++] = b[j++];
}
int main(void)
{
	srand(time(NULL));
	vector<int> arr;
	for(int i = 0; i < len; i++)
		arr.push_back(rand()%100);
	cout << "初始数组：";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	sort(arr,  0, arr.size()-1); //依旧基于下标的分治过程 
	
	cout << "排序数组：";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
