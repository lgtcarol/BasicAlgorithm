/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> q; 
        if(root == NULL)
             return res;
        q.push(root);
        vector<int> eachLevel;
        
        //下层的个数可以直接通过进入vector中元素个数知道
        int num1 = 1;
        int num2 = 0;

        //层次遍历中若想从队列中区分各层，则每层的个数应该是知道的。需要几个变量做这件事？
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            eachLevel.push_back(node->val); //每访问一个节点输出其到vector
            num1--;
            if(node->left)
            {
                q.push(node->left);
                num2++;
            }
            if(node->right)
            {
                q.push(node->right);
                num2++;
            }
            if(num1 == 0)
            {
                num1 = num2;
                num2 = 0;
                res.push_back(eachLevel);  //一层结束打印一层
                eachLevel.resize(0);
            }
        }
        return res;
    }
};
