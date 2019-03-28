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
		if(a[j] < laterPut) //˵���ҵ��˷��� laterReplace��λ�� 
			break;
		a[src] = a[j]; //û�ҵ��Ļ����ϵ�������λ�������� 
		src = j;
	}
	a[src] = laterPut; //srcʼ��ָ���λ�� 
}
void sort2(vector<int> &a)
{
	//������(������Ȼ�󶥶�)
	buildHeap(a); 
	//���ֵ����ѣ���n-1����
	for(int i = a.size()-1; i > 0; i--)
	{
		swap(a[0], a[i]);
		adjustHeap(a, 0, i-1); //param1Ϊ������param2Ϊ���������Χ 
	} 
}
int main(void)
{
	srand(time(NULL));
	vector<int> arr;
	for(int i = 0; i < len; i++)
		arr.push_back(rand()%100);
	cout << "��ʼ���飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
//	sort1(arr);
	sort2(arr); //С����һ��sizeΪ����ȡ���м䣬Ϊż��ȡ����һ�� 
	            // С���ɶ���������ż�������һ�������ڣ�len/2-1���� 
	cout << "�������飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
