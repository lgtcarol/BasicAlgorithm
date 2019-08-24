/*
1. Debug:这是个带有返回值的递归函数。子函数返回值该如何记载并逐层返回为问题的解！
2. 二叉搜索树的中序遍历，当对root的操作在中间部分时。
*/
class Solution {
    int cnt = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode *res = NULL;
        if(pRoot == NULL)
            return res;
        if(pRoot->left)
            res = KthNode(pRoot->left, k);
        if(!res)  //注意：这个res变量非常必要，因为找到后就不需要再遍历了！
        {
            cnt++;
            if(cnt == k)
                res = pRoot;           
        }

        if(!res && pRoot->right)
            res = KthNode(pRoot->right, k);
        return res;
    }
};
