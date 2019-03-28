// 变量声明问题 
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	cout << "hello" << n+1 << endl;
	int m;
	cin >> m;
	for(int i = 0; i < n; i++){
		cout << i;
	}
	for(int i = 0; i < m; i++){
		cout << i+2 << endl;
	}
	return 0;
}
