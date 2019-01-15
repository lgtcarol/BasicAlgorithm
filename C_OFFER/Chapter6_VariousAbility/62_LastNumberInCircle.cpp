// ������62��ԲȦ�����ʣ�µ�����
// ��Ŀ��0, 1, ��, n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
// ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�

#include <cstdio>
#include <list>

using namespace std;

// ====================����1====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    list<int> numbers;
    for(i = 0; i < n; ++ i)
        numbers.push_back(i);
   //lgt:��Ȼcurrent��ָ���һ��Ԫ�أ���ֻ���ټ�m-1����ﵽ��m��Ԫ�� 
   //lgt:���µ������Ķ��� �ɿ��� int��ָ�붨�� ����ָ��е������� 
    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)
    {
        for(int i = 1; i < m; ++ i)
        {
            current ++;
            //c.begin() ����һ������������ָ������c�ĵ�һ��Ԫ��
            //lgt NOTE:c.end() ����һ������������ָ������c�����һ��Ԫ�ص���һ��λ��
            if(current == numbers.end())
                current = numbers.begin();
        }
		//lgt_note:֮���Զ��һ����current++��current--�ǵ������������ƣ�û��current+1��ע���޸�currentֵ 
        list<int>::iterator next = ++current;
        if(next == numbers.end())
            next = numbers.begin();
		
        -- current;
        numbers.erase(current);
        current = next;
    }

    return *(current);
}

// ====================����2====================
/** ����https://blog.csdn.net/u010429424/article/details/73695062�е�˼·��
f(n,m)ʵ���Ǹ���
��ɾ������Ԫ�غ���������ӳ�䣬����ʾΪ�µĺ�����ʽ 
�ٽ��д���򻯵õ����ձ��ʽ 

�õ����ʽ�����ʵ�ֲ����ѣ��ص��Ƿ����õ���� 
*/ 
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i ++) 
        last = (last + m) % i;

    return last;
}

// ====================���Դ���====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    if(LastRemaining_Solution1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
