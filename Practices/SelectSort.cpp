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
//==============================================
void sort1(vector<int> &a)
{
	int len = a.size();
	for(int i = 0; i < len-1; i++)	
		{
			int min = i;
			for(int j = i+1; j < len; j++)
				if(a[j] < a[min])
					min = j;
			swap(a[i], a[min]);
		}
} 
//===============================================
void adjustHeap(vector<int> &a, int srcIndex, int rangeEnd);
void buildHeap(vector<int> &a)
{
	for(int i = a.size()/2-1; i >= 0; i--)
		adjustHeap(a, i, a.size());
}

void adjustHeap(vector<int> &a, int src, int end)
{
	int laterPut = a[src];
	for(int j = src*2; j < end; j*=2)
	{
		//int laterReplace = j;
		if(a[j] < a[j+1])
			j = j+1;
		if(a[j] < laterPut) //说明找到了符合 laterReplace的位置 
			break;
		a[src] = a[j]; //没找到的话往上调整，空位置往下走 
		src = j;
	}
	a[src] = laterPut; //src始终指向空位置 
}
void sort2(vector<int> &a)
{
	//建立堆(升序自然大顶堆)
	buildHeap(a); 
	//逐轮调整堆，共n-1次数
	for(int i = a.size()-1; i > 0; i--)
	{
		swap(a[0], a[i]);
		adjustHeap(a, 0, i-1); //param1为祸根，param2为允许调整范围 
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
	sort2(arr); //小技巧一：size为奇数取正中间，为偶数取靠右一个 
	            // 小技巧二：奇数和偶数的最后一个根都在（len/2-1）处 
	cout << "排序数组：";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
