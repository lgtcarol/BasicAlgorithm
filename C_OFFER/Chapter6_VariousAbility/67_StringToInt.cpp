
// ������67�����ַ���ת��������
// ��Ŀ������дһ������StrToInt��ʵ�ְ��ַ���ת��������������ܡ���Ȼ����
// ��ʹ��atoi�����������ƵĿ⺯����

#include <cstdio>
/** �ص���˼·�������ԣ�Ҫ�ж�����
1. �ܷ�תΪ�����ı�ǣ��˴�������Status�����Ƿ�ɹ���
2. �������
    �����ж��µ����������ǣ���洢������������һ��int�ͱ������˴��к��ԣ��мǣ���
3. ATTENTION����ת�������и����趼�����Ƿ��߼���������ͼ�����������Լ�ʵ��һ�±��߼����� 

*/ 
long long StrToIntCore(const char* str, bool minus);

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if(str != NULL && *str != '\0') 
    {
        bool minus = false;
        if(*str == '+')
            str ++;
        else if(*str == '-') 
        {
            str ++;
            minus = true;
        }

        if(*str != '\0') 
            num = StrToIntCore(str, minus);
    }

    return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0') 
    {
        if(*digit >= '0' && *digit <= '9') 
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7FFFFFFF) 
                || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }

            digit++;
        }
        else 
        {
            num = 0;
            break;
        }
    }

    if(*digit == '\0') //lgt��������������Ч�ķ���ֵ 
        g_nStatus = kValid;

    return num;
}

// ====================���Դ���====================
void Test(const char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //��Ч�����������, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //��Ч����С������, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}
