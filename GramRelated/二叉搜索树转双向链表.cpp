//心得：根节点的前驱是遍历左子树得到，将根节点链到链表上后，继续对右子树递归即可
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void ConvertNode(TreeNode *r, TreeNode **pL)
    {
        if(r == NULL)
            return ;
        TreeNode *pC = r;
        if(pC->left != NULL)
            ConvertNode(pC->left, pL);
        pC->left = *pL; //将根节点的前驱赋好
        if((*pL) != NULL)
            (*pL)->right = pC;
        *pL = pC; //把链表的末端节点置为当前根节点
        if(pC->right != NULL)
            ConvertNode(pC->right, pL);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pL = NULL;
        ConvertNode(pRootOfTree, &pL);
        TreeNode *pH = pL;
        while(pH != NULL && pH->left!= NULL)
            pH = pH->left;
        return pH;
    }

};
