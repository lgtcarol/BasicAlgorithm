// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <cstdio>
#include <list>

using namespace std;

// ====================方法1====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    list<int> numbers;
    for(i = 0; i < n; ++ i)
        numbers.push_back(i);
   //lgt:既然current已指向第一个元素，则只需再加m-1次则达到第m个元素 
   //lgt:如下迭代器的定义 可看做 int型指针定义 （该指针叫迭代器） 
    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)
    {
        for(int i = 1; i < m; ++ i)
        {
            current ++;
            //c.begin() 返回一个迭代器，它指向容器c的第一个元素
            //lgt NOTE:c.end() 返回一个迭代器，它指向容器c的最后一个元素的下一个位置
            if(current == numbers.end())
                current = numbers.begin();
        }
		//lgt_note:之所以多此一举先current++再current--是迭代器操作限制，没有current+1故注定修改current值 
        list<int>::iterator next = ++current;
        if(next == numbers.end())
            next = numbers.begin();
		
        -- current;
        numbers.erase(current);
        current = next;
    }

    return *(current);
}

// ====================方法2====================
/** 参照https://blog.csdn.net/u010429424/article/details/73695062中的思路三
f(n,m)实际是个数
将删除单个元素后的数组进行映射，并表示为新的函数形式 
再进行代入简化得到最终表达式 

得到表达式后进行实现并不难，重点是分析得到结果 
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

// ====================测试代码====================
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
