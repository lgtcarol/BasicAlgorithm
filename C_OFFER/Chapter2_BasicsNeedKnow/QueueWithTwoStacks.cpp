#include <stack>

#include <stdio.h>
#include <stdlib.h>
using namespace std;
template<typename T> class CQueue{
public:
	CQueue(void);
	~CQueue(void); 
	void appendTail(const T &node);
	T deleteHead(void);
private:
	stack<T> stack1;
	stack<T> stack2;
};
//哪怕是空的，构造函数和解析函数都要写！ 
template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}


template<typename T> void CQueue<T>::appendTail(const T &element)
{
	stack1.push(element);
}
template<typename T> T CQueue<T>::deleteHead(void)
{
	if(stack2.size() <= 0)
	{
		while(stack1.size() > 0)
		{
			T& t = stack1.top();//声明时直接为引用？ 
			stack1.pop();
			stack2.push(t);
		}
	}
	//若经历上步骤stack2仍为空，怀疑队列为空
	if(stack2.size() == 0)
    {
    	printf("相当于异常");
    	exit(1);
	}
//	if(stack2.size() == 0)
//	 	throw new exception("queue is empty");

	//注意：模板类型毕竟是类型不是变量，不要混淆 
	T head = stack2.top();
	stack2.pop();
	return head;
}
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;//直接在主类声明队列去用，T也被char代替 

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    return 0;
}

