// ������35����������ĸ���
// ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
// ��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
// ����⣬����һ��m_pSibling ָ�������е����������nullptr��

#include <cstdio>
#include "Utilities/ComplexList.cpp"
/** ������˼·֮������ֽ⡿ 
(1) ��������������⣬�������������ڵ㣬ͬ��һ�ⶼ���Ƚ��һ�� 
(2) ���ѷ���˼·��ڣ�nextָ������ӵ���nextsibiling��û�����ɰ����Ƚ���������õ���������Ȼ��ϸ��������Ľ� 
(3) �����ơ��������Ʊ���������ĺ������ 
*/

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

void CloneNodes(ComplexListNode* h) 
{
	if(h == NULL)
		return ;
	//����sibiling������ǵ�����ĸ����ء�����ϣ������������ƽڵ�Ķ�Ӧ��ϵ����һ��ָ��Ҫ����
	ComplexListNode* o = h;
	while(o != NULL)
	{
		ComplexListNode* c = new ComplexListNode();
		//ֵ���ƣ���ӽڵ�֮�����޸ģ�δ�����ÿ�
		c->m_nValue = o->m_nValue;
		c->m_pNext = o->m_pNext;
		o->m_pNext = c;
		c->m_pSibling = NULL; 
		o = c->m_pNext;//����ǰ�� 
	} 
}

void ConnectSiblingNodes(ComplexListNode* h)
{
	//ԭsibilingû�����ֽ���һ��һ���Ƶ�copy���ϵ�sibiling
	ComplexListNode* o = h;
	while(o != NULL)
	{
		//copy��ͨ��origin����next�����ƶ�
		ComplexListNode* c = o->m_pNext;
		if(o->m_pSibling != NULL) 
			c->m_pSibling = o->m_pSibling->m_pNext;//��Ȼ����null���� 
		o = c->m_pNext; //��cȡ��һ������origin���������¸��ڵ� 
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* h)
{
	//����sibiling�¶���ֻ�ǽ��߼�������copy�Ľڵ�������ϵ�������ɾ��
	ComplexListNode* o =  h;
	while(o != NULL)
	{
		ComplexListNode* c = o->m_pNext;
		if(c->m_pNext != NULL)
			o->m_pNext = c->m_pNext;//��Ȼ�ⲽ���޷���֤�����뱣֤Լ��������ַ�֧������������������������
		else
		{
			o->m_pNext = NULL;
			break; 
		} 
		c->m_pNext = o->m_pNext->m_pNext;//ǰ���Ѿ����Ա�֤o->m_pNext���� 
		o = o->m_pNext;//�����ƶ� 
		//�ڴ����һ�㣺nextָ�������ǽ�����־����ͬ��sibiling����ָ
		//������˫�ڵ�������copy��β��originҲ��β 
	} 
	return o;//����ָ��ֵ����������Ҫ����ֵ�� 
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

// ====================���Դ���====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSiblingָ��������
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling�γɻ�
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// ֻ��һ�����
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, NULL, pNode1);

    Test("Test4", pNode1);
}

// ³���Բ���
void Test5()
{
    Test("Test5", NULL);
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


























