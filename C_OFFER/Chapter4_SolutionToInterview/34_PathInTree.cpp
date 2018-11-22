/**
1.ͨ��˼·ѧϰ��
(1)��Ƶݹ麯�����л��ݣ��뺯�� Ϊһ��״̬���������ָ� 
(2)ջ��˼·���ݹ麯�������ʽ�Ϳ������㣩���Լ���ÿ����¼��ע����Ϣ������Ϊ�����ⲽҲ���Դ�ӡ֮ǰ���� ����Ϊ�ﵽĿ������ϸ��µ�ֵ
(3)���ڱ������ӡ֮ǰ���У������ü�¼����ʱstack�������ã�������vector(���ݽṹ�ϵ�˼��)
2.�������˼·�ܽ᣺
step1: �ݹ�����޸���Ϊ���������������޸�������currentSum��path��
step2: �ж������������ԣ�����󱾲��ĺ�����ȻҲ����ִ�У���������
step3: �������������������ȱ�����NOTE:��������ȥ��Ȼ����ֻ��һ��ѡ��ȻҲ�����ɻ��ݣ�����������̽���ػ�·����̽���̡� 
*/
#include <cstdio>
#include "Utilities\BinaryTree.cpp"
#include <vector>
//�﷨���⣺path������Ϊ������Ϊ��vector���ڴ�ע�����ñ������� 
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);

void FindPath(BinaryTreeNode* r, int tarSum)
{
	if(r==NULL || tarSum==0)
		return ;
	std::vector<int> path;
	int curSum = 0;
	FindPath(r, tarSum, path, curSum);
	return; 
} 
//���ڸ��ģ�curSum�������ã� �ǵģ�����������һ�¼��ٴ���˼����֧ 
void FindPath(BinaryTreeNode* r, int tarSum, std::vector<int>& path, int curSum)
{
	curSum += r->m_nValue;
	path.push_back(r->m_nValue);
	
	//ATTENTION: ���ⲻ����ÿ�������ʸ��ж��Ƿ�����ģ�������Ҷ�ڵ�
	if(r->m_pLeft==NULL || r->m_pRight==NULL)
	{
		if(curSum == tarSum)
		{
			printf("A path is founded!\n");
			//�����������������
			std::vector<int>::iterator iter = path.begin();
			for(; iter!=path.end(); iter++)
				printf("%d\t", *iter);
			printf("\n");	
	    }	
	} 
	if(r->m_pLeft != NULL)
		FindPath(r->m_pLeft, tarSum, path, curSum);
	if(r->m_pRight!=NULL)
		FindPath(r->m_pRight, tarSum, path, curSum);
	
	path.pop_back();
}

// ====================���Դ���====================
void Test(const char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// ������·���ϵĽ���Ϊ22
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// û��·���ϵĽ���Ϊ15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// ��һ��·������Ľ���Ϊ15
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// û��·������Ľ���Ϊ16
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test5()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// ����û�н��
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", NULL, 0);
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













































