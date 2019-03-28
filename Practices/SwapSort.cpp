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
	//��������ľ����±꣬��Ȼ�ô���
	//����������Ļ�,�����ԣ����Եݹ�ĳ��ڰ�
	if(l < h)
	{
		int m = partion(a, l, h);
		sort2(a, l, m-1); //�Ѿ��ź���һ��λ��
		sort2(a, m+1, h); 
	} 

}
int partion(vector<int> &a, int l, int h)
{
	int pvt = a[l]; //�ӵ�Ԫ�� a[l]����λ�� 
	while(l < h) //����Ϊ���������,�����ֲ����Ƕ���Ⱥ󻹵�ȷ����Ԫ�ص���߻����ұ� 
	{
		while(h > l && a[h]>pvt) //�±�Ƚ������ȡ�ȣ��Ⱥ���������������Լ��Ļ�����Խ����ô! 
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
	cout << "��ʼ���飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
//	sort1(arr);
	sort2(arr,  0, arr.size()-1); 
	
	cout << "�������飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
