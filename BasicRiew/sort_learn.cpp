//[笔记一] 自定义排序规则即第三个参数
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
	
/**
[笔记二]  也可以使用C++库中已有的排序函数，在<functional>头文件中，有equal_to<Type>、not_equal_to<Type>、greater<Type>、greater_equal<Type>、
less<Type>、less_equal<Type>，可以直接作为comp函数
*/
#define<functional>
sort(A,A+100,greater<int>());//降序排列
sort(A,A+100,less<int>());//升序排列
/**
[笔记三] 不是所有的容器直接用sort函数的，有些容器自带有sort函数，
不能使用sort(name.begin(), name.end(), comp)，只要用name.sort(comp)即可，比如list容器。
*/
#include <list>
#include <iostream>
int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;

   c1.push_back( 20 );
   c1.push_back( 10 );
   c1.push_back( 30 );

   cout << "Before sorting: c1 ="; //here
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.sort( ); 。//here
   cout << "After sorting c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.sort( greater<int>( ) ); //here
   cout << "After sorting with 'greater than' operation, c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;
}
