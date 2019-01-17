// ������68����������������͹�������
// ��Ŀ��������������㣬�����ǵ���͹������ȡ�

#include <cstdio>
#include "Utilities\Tree.cpp"
#include <list>

/**
�������б�Ҫ����Tree.h��Tree.cpp��������ṹ���壬���Ƕ�����
1. ÿ���ڵ�ĺ��ӽڵ���ͨ��TreeNode*�����洢�� 
2. ���жԺ��ӽڵ����ȱ��������ҵ�ָ���ڵ㣬�ҵ��򷵻أ���ʱ����ջ�еļ�Ϊ�����ĸ��ڵ�
3. ˼·���ֱ�Ѱ�������ڵ������е�·�������߹��е����һ���ڵ���Ϊ��͹������� 
*/ 
using namespace std;

//lgt:��Ȼ��ȱ����ʺϵ�·���洢�ṹӦ����ջ���ʴ˴�pathģ��ջ�洢���� 
bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
    if(pRoot == pNode)
        return true;
 
    path.push_back(pRoot);
 
    bool found = false;

    vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
    while(!found && i < pRoot->m_vChildren.end()) //lgt:һ���ҵ������� ֹͣ�������ʴ˴������ѭ���߼�Ҫ��Ϥ 
    {
        found = GetNodePath(*i, pNode, path);//lgt:�ݹ���� 
        ++i;
    }
 
    if(!found)
        path.pop_back();//lgt:���ڵ�ǰ�ڵ�ĺ��ӽڵ���û�ҵ�����ǰ�ڵ�Ҳ��ջ�������Լ�ģ�⣩ 
 
    return found;
}

/** ѧϰ�ʼ�
1. C++ STL �ⲻ�������ڶ���ʱ����ͨ�������͸���Щ������ �ؼ���+�����ţ������������ټ��� ::+iterator 
2. ������.������() ���ÿⷽ�����ɣ������ܽ��³���ģ���ͺ���
3. NOTE��GetLastCommonNodeʵ�ʾ��������б�����󹫹��ڵ� ,���ҽ�֮ǰĳ����Ը��򵥣���ͷ��ʼ�ض�ͬʱ�ƶ�ָ�룩 
*/ 
const TreeNode* GetLastCommonNode
(
    const list<const TreeNode*>& path1, 
    const list<const TreeNode*>& path2
)
{
    list<const TreeNode*>::const_iterator iterator1 = path1.begin();
    list<const TreeNode*>::const_iterator iterator2 = path2.begin();
    const TreeNode* pLast = NULL;
 
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2) //list�зŵĲ���TreeNodeָ�룬��ȡ* 
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return pLast;
}

const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
    if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
 
    list<const TreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);
 
    list<const TreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);
 
    return GetLastCommonNode(path1, path2);
}

// ====================���Դ���====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2, TreeNode* pExpected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    const TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == NULL && pResult == NULL) || 
        (pExpected != NULL && pResult != NULL && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ��״��ͨ����
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// ���˻���һ������
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// ���˻���һ������һ����㲻������
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    TreeNode* pNode6 = CreateTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, NULL);
}

// ����NULL
void Test4()
{
    Test("Test4", NULL, NULL, NULL, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
