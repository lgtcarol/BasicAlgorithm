#include <cstdio>
bool matchCore(const char* str, const char *pattern);
bool match(const char* str, const char *pattern)
{
	if(str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}
//Note: strָ����ƶ�����ƥ�䣬patternָ����ƶ�����ģʽ������״̬������ת�� 
bool matchCore(const char* str, const char *pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*pattern == '\0' && *str != '\0')//ģʽ�����������꣬��ģʽ����a*�ɴ���û�У����ַ�����ʲô����ʲô 
		return false;

	//Note:���ڼ򵥵�һ��һ����ƥ����ԣ�����*�Ĵ���ʹƥ�������ȷ��״̬��������״̬������
	//Note:��˼·�Զ��׼���*��Ϊ���۴��࣬��*�Ĺ�Ч��ǰ���ַ��������Բ�����ǰchar+['*']���˼· 
	if(*(pattern+1) == '*') 
	{
		//pattern+2����ζ����ģʽ��״̬�����¸�״̬��pattern��������ѭ��״̬
		//str+1����ζƥ��ɹ����������ƥ�䣬��Ȼ+1���㹻��,str��δƥ���ӦΪpattern��0ƥ�书������pattern+2(a*��ƥ��0���ַ�) 
		//����ǰcharƥ�������¸�Ϊ*,һ���¸�str���ǵ�ǰpattern(ģʽ����)�������¸�str���ǵ�ǰpattern 
		if(*str==*pattern || (*str!='\0' && *pattern=='.'))
			return matchCore(str+1, pattern+2)||matchCore(str+1, pattern)||matchCore(str, pattern+2);
		else
			return matchCore(str, pattern+2);//��ǰ�ַ�ƥ��ʧЧ����Ȼ����a*��0ƥ�书�� 
	}
	else
	{
		if(*str==*pattern || (*str!='\0' && *pattern=='.'))
			return matchCore(str+1, pattern+1);
	}
	//�¸��ַ�Ϊ*���������Ĳ�ȷ���ԣ�����Ϊ��ͨ��ƥ����� 
	//Note������'.'�����Թ�Ҫ��֤�䲻ƥ��'\0'  
	//Note: ��ʵ�ܷ�����ģʽ�����Ƚ��� 
	return false;
	//if-else������ƥ������µ����ƣ�����һ����ƥ��������ʧ�ܣ� 
}

// ====================���Դ���====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
//����ģʽ�������������ʹ������ķ�����ʵ�Ǹ�������״̬�����еģ�˼·���ַ���������������֧�� 
