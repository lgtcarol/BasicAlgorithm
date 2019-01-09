// ������55��������ƽ�������
// ��Ŀ������һ�ö������ĸ���㣬�жϸ����ǲ���ƽ������������ĳ��������
// ��������������������������1����ô������һ��ƽ���������

#include <cstdio>
#include "Utilities\BinaryTree.cpp"

// ====================����1====================
/**
1. ����54��������⣬���Է��������ǰ�ڵ����������ĸ߶Ȳ飬����ǰ�ڵ��ƽ����������
2. �ϲ���������ǰ�ڵ�������ٶԱ�������IsBalanced_Solution1�ĵݹ�λ�ã��˷��൱����ǰ�����
3. Note:����ֽ�˼·��������ƽ����������ƽ�⣬��������ƽ�� 
   Learn: ��˼·һ��˼·�����ݱ䣻ֵ���غͲ������ص������ԣ���θĽ�Ϊ������� 
*/ 
int TreeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);
   
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution1(const BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
        return true;

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;
    if(diff > 1 || diff < -1) 
        return false;

    return IsBalanced_Solution1(pRoot->m_pLeft) 
        && IsBalanced_Solution1(pRoot->m_pRight);
}

// ====================����2====================
bool IsBalanced(const BinaryTreeNode* p, int *d);
bool IsBalanced_Solution2(const BinaryTreeNode*p)
{
	int d = 0;
	return IsBalanced(p, &d); //�ڶ��������Ǳ��ֵݹ麯���һ���� 
}
bool IsBalanced(const BinaryTreeNode* p, int *d)
{
	if(p == NULL)
	{ 
		*d = 0;//��ȳ�ʼ�� 
		return true;
	} 
	int left, right;
	if(IsBalanced(p->m_pLeft, &left) && IsBalanced(p->m_pRight, &right))
	{
		int diff =  left-right;
		if(diff <= 1 && diff >= -1)
		{
			*d = 1 + (left > right ? left : right);
			return true;
		}//��˼���˴��õ��Ǵ�������ȣ�����ÿ������Ҫ�Ը߶Ƚ����޸ģ�ѡ��ǰ���ĸ߶ȸ�ֵ����1 
	}
}



// ====================���Դ���====================
void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if(IsBalanced_Solution1(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if(IsBalanced_Solution2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ��ȫ������
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, pNode6, pNode7);

    Test("Test1", pNode1, true);

    DestroyTree(pNode1);
}

// ������ȫ������������ƽ�������
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, NULL, pNode6);
    ConnectTreeNodes(pNode5, pNode7, NULL);

    Test("Test2", pNode1, true);

    DestroyTree(pNode1);
}

// ����ƽ�������
//             1
//         /      \
//        2        3
//       /\         
//      4  5        
//        /
//       6
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, pNode6, NULL);

    Test("Test3", pNode1, false);

    DestroyTree(pNode1);
}


//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode5, NULL);

    Test("Test4", pNode1, false);

    DestroyTree(pNode1);
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
void Test5()
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

    Test("Test5", pNode1, false);

    DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test6", pNode1, true);

    DestroyTree(pNode1);
}

// ����û�н��
void Test7()
{
    Test("Test7", NULL, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

