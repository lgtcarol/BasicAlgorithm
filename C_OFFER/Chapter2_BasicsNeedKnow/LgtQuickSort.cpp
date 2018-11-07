#include <stdio.h>
#include <stdlib.h>
#define N 5
//��ͬ�������������������������ͬΪ��̬�滮�𲽻���Ϊ��ͬ�������⣬���仮�ֹ��̺�ÿ�λ��ֵľ��巽����Ϊ��һ���ڽ���
//���֮�£����㷨��Partion��������������Ӧ�ĺ�������֧������������������רһ�Ļ��֣��Ӷ��õ��ڱ�������ֱ�ӵݹ�������� 
int Partion(int a[], int s, int e)
{
	int mid = a[s];
	while(s<e)
	{

		while(s<e && a[e] >= mid)
			e--;
		if(s==e)
			break;
		else
			a[s++] = a[e];//���eΪ����ֵ
		while(s<e && a[s] < mid)
			s++;
		if(s==e)
			break;
		else
			a[e--] = a[s];
	}	
	return s;	
}
void QuickSort(int a[], int s, int e)
{
	int mid = Partion(a, s, e);
	if(mid > s)
		QuickSort(a, s, mid-1);
	if(mid < e)
		QuickSort(a, mid+1, e);		
}
int main(void)
{
	int a[] = {3,4,5,11, 111};
	QuickSort(a,0,N-1);
	printf("Sorted: \n");
	for(int i = 0; i < N; i++)
		printf("%d\t", a[i]);
	return 0;
 } 

 
 
 
 
 
 
 
 
