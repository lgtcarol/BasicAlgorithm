//Debug:比较有成就感的一次递归分析
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
    vector<vector<int> > res;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        if(root == NULL)
            return res;
        dfs(root, expectNumber);
        return res;
    }
    void dfs(TreeNode *root, int en)
    {
        if(root == NULL)
            return;
        tmp.push_back(root->val);
        if((en-root->val)==0 && (root->left==NULL) && (root->right==NULL))
        {
             res.push_back(tmp);
             tmp.pop_back(); //Debug:由于找所有路径，本次操作成功后也需保证返回层相应值得正确。因pop_back原计划必执行，而在本处得返回使得程序"异常"结束
             return;           
        }
        if(root->left)
            dfs(root->left, en-root->val);
        if(root->right)
            dfs(root->right, en-root->val);
        if(tmp.size() > 0)
        tmp.pop_back();
        return;
    }
};
