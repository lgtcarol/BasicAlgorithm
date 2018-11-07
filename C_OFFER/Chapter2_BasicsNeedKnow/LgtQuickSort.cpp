#include <stdio.h>
#include <stdlib.h>
#define N 5
//不同于由先序和中序建立二叉树，虽同为动态规划逐步划分为相同的子问题，但其划分过程和每次划分的具体方法融为了一体在进行
//相比之下，本算法的Partion函数将二叉树对应的函数内旁支操作进行提炼，进行专一的划分，从而得到在本函数可直接递归的子问题 
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
			a[s++] = a[e];//如今e为无用值
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

 
 
 
 
 
 
 
 
