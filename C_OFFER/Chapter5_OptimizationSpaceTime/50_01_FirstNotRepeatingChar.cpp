// ������50��һ�����ַ����е�һ��ֻ����һ�ε��ַ�
// ��Ŀ�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������
// 'b'��

#include <cstdio>
#include <string>

char FirstNotRepeatingChar(const char* s)
{
    if(s == NULL)
        return '\0';	
        
    int *bin = new int[256];
    const char* p = s;
    for(int i = 0; i<256; i++)
    	bin[i] = 0;
    while((*s) != '\0')
    {
    	bin[(*s)]++;
    	s++;
	}
	while((*p) != '\0') //���ַ�����������ʡʱ�� 
	{
		if(bin[*p] == 1)
			return *p;
		p++; 
	}
	return '\0';
}



// ====================���Դ���====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // ����������ԣ�����ֻ����һ�ε��ַ�
    Test("google", 'l');

    // ����������ԣ�������ֻ����һ�ε��ַ�
    Test("aabccdbd", '\0');

    // ����������ԣ������ַ���ֻ����һ��
    Test("abcdefg", 'a');

    // ³���Բ��ԣ�����nullptr
    Test(NULL, '\0');

    return 0;
}
