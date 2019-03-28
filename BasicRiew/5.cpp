#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v1(10); //默认初始化为0. size和resize可以随时分配大小 
	v1.resize(8); 
	cout << v1.size() << endl;
	
	vector<int> v(100, 9); //初始值为9
	cout << v[0]; //可用下标访问 
	return 0;
}
 
