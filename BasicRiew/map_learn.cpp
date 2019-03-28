#include <iostream>
#include <map>
#include <string> 
using namespace std; 
int main() 
{    
	map<string, int> m; // ����?һ���յ�map m������string���͵ģ�ֵ��int���͵�    
	m["hello"] = 1; // ��keyΪ"hello", valueΪ2�ļ�ֵ��(key-value)��?��map��    
	cout << m["hello"] << endl; // ����map��keyΪ"hello"��value, ���key�������ڣ��� ��0   
	cout << m["world"] << endl;    
	m["world"] = 2; // ��"world"����Ӧ��ֵ�޸�Ϊ3    
	m["lgt"] = 3; // ��?��?һ���ֵ�ԣ���Ϊ"," ֵΪ1  
	
	for (auto it = m.begin(); it != m.end(); it++)
	{        
	 cout << it->first << " " << it->second << endl;
	}
	cout << m.size() << endl; //�ֵ���Ԫ�ظ���Ϊ3 
	cout << "�ֱ����map�е�һ����ֵ�ԣ������һ����ֵ��" << endl;
	cout << m.begin()->first << ' ' << m.begin()->second << endl;
	cout << m.rbegin()->first << ' ' << m.rbegin()->second << endl; 
	return 0; 
}

/**
<unordered_map>ʡȥ��<map>�ᰴkey����ù��̣�Ч�ʸ���
<unordered_set>ʡ��<set>��Ԫ�ش�С������������ 
*/ 

