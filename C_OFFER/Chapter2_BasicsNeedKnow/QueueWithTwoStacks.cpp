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
//�����ǿյģ����캯���ͽ���������Ҫд�� 
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
			T& t = stack1.top();//����ʱֱ��Ϊ���ã� 
			stack1.pop();
			stack2.push(t);
		}
	}
	//�������ϲ���stack2��Ϊ�գ����ɶ���Ϊ��
	if(stack2.size() == 0)
    {
    	printf("�൱���쳣");
    	exit(1);
	}
//	if(stack2.size() == 0)
//	 	throw new exception("queue is empty");

	//ע�⣺ģ�����ͱϾ������Ͳ��Ǳ�������Ҫ���� 
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
    CQueue<char> queue;//ֱ����������������ȥ�ã�TҲ��char���� 

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

