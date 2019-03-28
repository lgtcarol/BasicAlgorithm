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
		int tmp = a[i]; //����Ԫ�أ���ǰa[i]������ 
		int j = i-1; 
		for(; j >= 0 && a[j]>tmp; j--) //��Ѿ��Ȼ�Ǹ��̶�ֵ�ȣ����ﲻ�ó��±� 
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
			//�ƶ�����û�б䣬��a[i]Ϊ��Ŧ����벿���ƶ���������sָ��a[i]��Ŀ��λ�� 
			if(a[m] > tmp)
				e = m-1;
			else 				//��ʹ���Ҳ����ź�벿�� 
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
	cout << "��ʼ���飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
//	sort1(arr);
	sort2(arr); 
	
	cout << "�������飺";
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
} 
