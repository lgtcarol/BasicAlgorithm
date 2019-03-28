#include <algorithm>
#include <iostream>
using namespace std;

/**
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/
class Solution {
	string s;
	string tmp;
	int strlen;
	vector<string> ret; //ȫ�� 
	vector<int> used;
	
	void dfs(int step){
		if(step == strlen)
		{
			ret.push_back(tmp);//ÿ�ҵ�һ���������������յ������С� 
			return;
		 } 
		 for(int i = 0; i < strlen; i++)//ö�ٵ�ǰ�������ѡ�� ��for��������ͬ���� 
		{
			if(used[i]) //ȫ���У��ù��Ĳ��� 
				continue;
			if(i > 0 && s[i] == s[i-1] && !used[i-1]) //�����ظ��ַ��Ĵ��� 
				continue;
			tmp[step] = s[i];
			used[i] = 1; //����ѡ���������²� 
			dfs(step+1);
			used[i] = 0; //����δ�ӱ�����ȥ����Ȼ���ñ�� 
		}
	}
public:
    vector<string> Permutation(string str) {
        if(str.empty())
        	return vector<string>();
        
        s = str;
        strlen = s.length();
        
        sort(s.begin(), s.end());
        tmp.resize(strlen, '\0'); //����������ʼ�� 
        used.resize(strlen, 0);
        
        dfs(0);
        return ret;
    }
};
int main(void)
{
	string test = "ab";
	Solution T;
	vector<string> ret = T.Permutation(test);
	for(auto it = ret.begin(); it != ret.end(); it++)
		cout  << *it << ' ';
	cout << endl;
	return 0;	
} 
