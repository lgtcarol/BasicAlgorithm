#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;
const int len = 15;
void sort1(vector<int> &a)
{
	int len = a.size();
	int i = 0;
	for(i = 1; i < len; i++)
	{
		int tmp = a[i]; //待放元素，当前a[i]视作空 
		int j = i-1; 
		for(; j >= 0 && a[j]>tmp; j--) //你丫既然是跟固定值比，干嘛不用扯下标 
		{
			a[j+1] = a[j];
		}
		if(j < 0)
			a[0] = tmp;
		else
			a[j+1] = tmp;
	}
}

void sort2(vector<int> &a)
{

	for(int i = 1; i < len; i++)
	{
		int s = 0;
		int e = i-1;
		int tmp = a[i];
		while(s <= e)
		{
			int m = (s+e)/2	;
			//移动操作没有变，以a[i]为枢纽将后半部分移动。故最终s指向a[i]的目标位置 
			if(a[m] > tmp)
				e = m-1;
			else 				//即使相等也倾向放后半部分 
				s = m+1;
		} 
		for(int j = i-1; j >= s; j--)
			a[j+1] = a[j];
		a[s] = tmp; 	
	}	
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
	sort2(arr); 
	
	cout << "排序数组：";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
