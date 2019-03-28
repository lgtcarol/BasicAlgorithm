//插入排序
#include <iostream>
#include <vector>
using namespace std;

void quickMain(int a[], int low, int high);
void adjustDown(int a[], int i, int len);

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void directInsert(int a[], int len )
{
	for(int i = 2; i < len; i++)
	{
//		int t = a[i];
		cout << a[i] << endl;
		int j;
		if(a[i-1] > a[i])
		{
			a[0] = a[i];
			for(j = i-1; a[0] < a[j]; j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = a[0];	 			
		}

	} 
	cout << "i have sorted!" << endl;
	return;
}

void halfInsert(int a[], int len) //不设置哨兵了 
{
	int low = 0;
	int high = len-1;
	for(int i = 1; i < len; i++)
	{
		low = 0;
		int tmp = a[i];
		high = i-1;
		cout << "in the while:" << a[i] << endl;
		while(low <= high)
		{

			int mid = (low+high)/2;
			if(tmp > a[mid]) 
				low = mid+1;
			else
				high = mid-1;
		}//high指向该插入位置
		for(int j = i-1; j > high; j--) //在移动时只能从后开始移动 
			a[j+1] = a[j];
		a[high+1] = tmp; 
	}
}
void bubbleSort(int a[], int len)
{
	bool flag = false;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = 0; j < len-1-i; j++)
		{
			flag = true;
			if(a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
				flag = false;	
			}	
		}
		if(flag == true)
			break;
	}
}


void quickSort(int a[], int len)
{
	quickMain(a, 0, len-1);
}
int Partition(int a[], int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while(a[high] >= pivot && low < high) //找到一个比pivot小的元素，所以取等号！！！ 
			high--;
		a[low] = a[high];
		while(a[low] <= pivot && low < high )
			low++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void quickMain(int a[], int low, int high)
{
	if(low < high)
	{
		int mid = Partition(a, low, high);
		quickMain(a, low, mid-1);
		quickMain(a, mid+1, high);
	}
}

void selectSort(int a[], int len)
{
	for(int i = 0; i < len-1; i++)
	{
		int target = i; //候选值下标 
		for(int j = i+1; j < len; j++)
		{
			if(a[j] < a[target])
				target = j;
		}
		swap(a[i], a[target]);
	}
}
//=================================================================== 
void buildMaxHeap(int a[], int len)
{
	//建堆过程实际是从最后一个根节点的调整过程
	for(int i = len/2; i >=0; i--) //向下取整 
		adjustDown(a, i, len);//用掉0号元素,调整i为根的子树	
} 
void adjustDown(int a[], int k, int len) //大顶堆 
{
	int t = a[k];
	for(int j = k*2; j < len; j*=2)
	{
		if(j < len-1 && a[j] < a[j+1]);
			j++;
		if(t >= a[j])
			break;
		a[k] = a[j];
		k = j; //改调j为根的子树 
	}
	a[k] = t; 
}
void heapSort(int a[], int len)
{
	buildMaxHeap(a, len);
	for( int i = len-1; i > 0; i--)
	{
		swap(a[i], a[0]);
		adjustDown(a, 0, i-1);
	}
}

//===============================================
int *b = new int[9];
void merge(int a[], int low, int mid, int high)
{
	int len = high-low+1;
//	int *b = new int[len];
	cout << "hello" << endl;	
	int i, j, k;
	for(k = low; k <= high; k++)
		b[k] = a[k];
	for(i = low, j = mid+1, k = low; i<=mid && j<=high; k++)
	{
		if(b[i] < b[j])
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while(i <= mid)
		a[k++] = b[i++];
	while(j <= high)
		a[k++] = b[j++];
//	delete[] b;
} 
void mergeSort(int a[], int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low , mid, high);//分成两部分，再将二者合并	
	}	
}

int main()
{
//	int a[] = {0, 2, 3, 1, 33, 2, 4, 8, 0};
	int a[] = {0, 2, 3, 1, 33, 2, 4, 8, 0};
	
//	directInsert(a, 9); 直接插入 
//	halfInsert(a, 9);   折半插入 
//	bubbleSort(a, 9); 	冒泡排序
//	quickSort(a, 9); 	快速排序 
//	selectSort(a, 9);  	选择排序
	heapSort(a, 9);		// ?堆排序
//	mergeSort(a, 0, 8);   归并排序：原来归并中占用的辅助空间都是局部的 
	delete[] b;
	for(int i = 0; i < 9; i++)
		cout << a[i] << ' '; 
//	vector<int> arr(a, a+sizeof(a)/sizeof(int)); 
//	for(auto it = arr.begin(); it != arr.end(); it++)
//		cout << *it << ' ';
	cout <<"over" << endl;
	return 0;
}
