#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;
bool cmp(int a, int b) 
{
	return a>b; //该逻辑为真 是标准!(所以是降序)	
} 
int main() 
{
	vector<int> v(10);
	for(int i = 0; i < 10; i++)
		cin >> v[i];
	sort(v.begin(), v.end());  //vector使用 
	for(int i = 0; i < 10; i++)
		cout << v[i] << " ";
	
	int arr[10];
	cout << endl;
	for(int i = 0; i < 10; i++)
		cin >> arr[i];
	
	sort(arr, arr+10, cmp); //数组使用！ 
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
} 
	

