#include <iostream>
#include <map>
#include <string> 
using namespace std; 
int main() 
{    
	map<string, int> m; // 定义?一个空的map m，键是string类型的，值是int类型的    
	m["hello"] = 1; // 将key为"hello", value为2的键值对(key-value)存?入map中    
	cout << m["hello"] << endl; // 访问map中key为"hello"的value, 如果key不不存在，则返 回0   
	cout << m["world"] << endl;    
	m["world"] = 2; // 将"world"键对应的值修改为3    
	m["lgt"] = 3; // 设?立?一组键值对，键为"," 值为1  
	
	for (auto it = m.begin(); it != m.end(); it++)
	{        
	 cout << it->first << " " << it->second << endl;
	}
	cout << m.size() << endl; //字典中元素个数为3 
	cout << "分别输出map中第一个键值对，和最后一个键值对" << endl;
	cout << m.begin()->first << ' ' << m.begin()->second << endl;
	cout << m.rbegin()->first << ' ' << m.rbegin()->second << endl; 
	return 0; 
}

/**
<unordered_map>省去了<map>会按key排序得过程，效率更高
<unordered_set>省掉<set>按元素从小到大得排序过程 
*/ 

