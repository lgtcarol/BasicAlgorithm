#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v1(10); //Ĭ�ϳ�ʼ��Ϊ0. size��resize������ʱ�����С 
	v1.resize(8); 
	cout << v1.size() << endl;
	
	vector<int> v(100, 9); //��ʼֵΪ9
	cout << v[0]; //�����±���� 
	return 0;
}
 
