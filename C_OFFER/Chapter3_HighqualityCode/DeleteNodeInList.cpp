//#include "Utilities/List.h"
#include "Utilities/List.cpp"
#include <cstdio>

void DeleteNode(ListNode **head, ListNode *tar)
{
	if(*head == NULL || tar == NULL)
		return ;
	//O(1)˼·�������߸���
	//����������ɾ����ͷ��β��û�к��� 

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
		*head = NULL;//����tarͬ����β��Ҳ��Ӱ�죬����������������tarΪβ�Ĵ����л��ֳ� 
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
	//��Ȼ�ǰ���������˳����������������Ӽ����⣬�Ͱ��ո�˳��ʵ�֣���Ҫ����˳�� 
}

// ====================���Դ���====================
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

// �������ж����㣬ɾ���м�Ľ��
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

// �������ж����㣬ɾ��β���
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

// �������ж����㣬ɾ��ͷ���
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

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
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
//debug�������ѭ����Ȼ����Ϊ��== �� =, ������������ֲ��ˣ����� 

