//#include "Utilities/List.h"
#include "Utilities/List.cpp"
#include <cstdio>

void DeleteNode(ListNode **head, ListNode *tar)
{
	if(*head == NULL || tar == NULL)
		return ;
	//O(1)思路，即后者覆盖
	//两个隐患：删除了头；尾部没有后驱 

	if(tar->m_pNext != NULL)
	{
		ListNode *tmp = tar->m_pNext;
		tar->m_nValue = tmp->m_nValue;
		tar->m_pNext = tmp->m_pNext;
		delete tmp; 
		tmp = NULL;
	}
	else if(*head == tar)
	{
		*head = NULL;//就算tar同样是尾部也不影响，本来此情况就算基于tar为尾的大类中划分出 
		delete tar;
		tar = NULL; 
	}
	else
	{
		ListNode *tmp = *head; 
		while(tmp->m_pNext != tar && tmp != NULL)
			tmp = tmp->m_pNext;
		tmp->m_pNext = NULL;
		delete tar;
		tar = NULL;
	}
	//既然是按着那样的顺序分析出三个互斥子集问题，就按照该顺序实现，不要调整顺序 
}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(NULL, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
//debug半天的死循环竟然是因为：== 错当 =, 这个编译器发现不了！！！ 

