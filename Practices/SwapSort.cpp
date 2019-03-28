#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;
const int len = 10;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;	
}
//=========================================================
void sort1(vector<int> &a)

{
	int len = a.size();
	for(int i = 0; i < len-1; i++)
		for(int j = 0;  j < len-i-1; j++)
		{
			if(a[j+1] < a[j])
				swap(a[j+1], a[j]);	
		}	
} 
//===========================================================
int partion(vector<int> &a, int l, int h);
void sort2(vector<int> &a, int l, int h) 
{
	//分治面向的就是下标，自然得传递
	//本步不检验的话,不可以！！自递归的出口啊
	if(l < h)
	{
		int m = partion(a, l, h);
		sort2(a, l, m-1); //已经放好了一个位置
		sort2(a, m+1, h); 
	} 

}
int partion(vector<int> &a, int l, int h)
{
	int pvt = a[l]; //子单元的 a[l]处空位置 
	while(l < h) //我认为相等无意义,而二分插入那儿相等后还得确定该元素的左边还是右边 
	{
		while(h > l && a[h]>pvt) //下标比较这儿不取等，等号情况还允许自增自减的话不就越界了么! 
			h--;
		a[l] = a[h];
		while(l < h && a[l]<=pvt)
			l++;
		a[h] = a[l];
	}	
	a[l] = pvt;
	return l;
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
//	sort1(arr);
	sort2(arr,  0, arr.size()-1); 
	
	cout << "排序数组：";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
