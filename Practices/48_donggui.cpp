#include <algorithm>
#include <iostream>
#include <vector> 
#include <set>
using namespace std;

//method1:���� 
int longestSubstringWithoutDuplication(const string& s) 
{
	if(s.size() == 0)
		return 0;
	int max = 0;
	string maxS;
	for(int i = 0; i < s.length(); i++ )
	{
		string tmp = s.substr(i,1);
		int cnt = 1;
		for(int j = i+1; j < s.length(); j++)
		{
			if(tmp.find(s[j],0) < j) //˵���ظ� 
				break; 
			cnt++;
			tmp+=s[j];
		}
		if(max < cnt)
		{
			max = cnt;
			maxS = tmp;
		}
	}
		cout << "the longest you find:" << maxS << endl;
		return max;

	return max; 
}

//method2: ���ݽṹset���Խ���Ϊn^2
//�ʼǣ�����insert��ͬԪ�� size����仯 
int longestSubstringWithoutDuplication(const string &s)
{
	int max = 0;
	int olen = 0;
	int j = 0; 
	for(int i = 0; i < s.length(); i++)
	{
		set<int> ss;
		ss.insert(s[i]);
		for(j = i+1; j<s.length(); j++)
		{
			olen = ss.size();
			ss.insert(s[j]);
			if(ss.size()< olen+1)
				break;
		}
		if(j== s.length())
			olen += 1; //����ԭ��һ��ʱ�ļ�� 
		if(olen > max)
			max = olen;
	}
	return max;
} 
//method3:��̬�滮����ȷ�����⣬����ʽ�� 
int longestSubstringWithoutDuplication(const string &s)
{
	//�������ƹ�������Ҫ��Щ����
	if(s.empty())
		return 0;
	int len = s.length();
	vector<int> fun(len, 1); //��ʽ����� //����ÿ��λ�õĳ�ʼ����ֵ��1 
	vector<int> visited(26, -1); //��ʽ�е������ж���Ҫ�������ϴεķ���״̬
	//�ѵ㣺����ֻ���Ǳ�����ǰ��������ô�з��ʹ� 
	//�״�㣺�������Ԫ�س�ʼ��
	visited[s[0]-'a'] = 0; //��̬�滮һ��Ҫע�⣺�����±��1��ʼִ�ж��飬��ô��һ��λ�õĻ�����Ϣ�أ��� 
	for(int i = 1; i < len; i++)
	{
		//��x���л����ж�
		int pre = visited[s[i]-'a'];  //δ���ʱ���һ���Ǹ��� 
		if(pre<0 || i-pre > fun[i-1] )
			fun[i] = fun[i-1]+1;
		else
			fun[i] = i-pre;
		visited[s[i] - 'a'] = i; //���龭���漰�������״̬���¼�����޸� 
	} 
	int max = -1;
	for(int i = 0; i < len; i++)
	{
		if(fun[i] > max)
			max = fun[i];
	}
	return max;
} 


int main() {
    cout << longestSubstringWithoutDuplication("abcacfrar") << endl;  // 4
    cout << longestSubstringWithoutDuplication("acfrarabc") << endl;  // 4
    cout << longestSubstringWithoutDuplication("arabcacfr") << endl;  // 4
    cout << longestSubstringWithoutDuplication("aaaa") << endl;       // 1 
    cout << longestSubstringWithoutDuplication("abcdefg") << endl;    // 7 
    cout << longestSubstringWithoutDuplication("a") << endl;           // 1
    cout << longestSubstringWithoutDuplication("aaabbbccc") << endl;  // 2
    cout << longestSubstringWithoutDuplication("abcdcba") << endl;    // 4
    cout << longestSubstringWithoutDuplication("abcdaef") << endl;    // 6
    
//	set<int> s;
//	s.insert(1);
//	s.insert(1);
//	cout << s.size();
    return 0;
}




































