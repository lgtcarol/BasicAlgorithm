#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;
bool cmp(int a, int b) 
{
	return a>b; //���߼�Ϊ�� �Ǳ�׼!(�����ǽ���)	
} 
int main() 
{
	vector<int> v(10);
	for(int i = 0; i < 10; i++)
		cin >> v[i];
	sort(v.begin(), v.end());  //vectorʹ�� 
	for(int i = 0; i < 10; i++)
		cout << v[i] << " ";
	
	int arr[10];
	cout << endl;
	for(int i = 0; i < 10; i++)
		cin >> arr[i];
	
	sort(arr, arr+10, cmp); //����ʹ�ã� 
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
} 
	

