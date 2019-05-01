//思路正确，但在输出上出现bug,具体看下面注解
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot==NULL)
            return result;
        stack<TreeNode*> stack1,stack2;//分别存奇数和偶数层
        stack1.push(pRoot);
        while(!stack1.empty() || !stack2.empty())
        {
            //虽说这个判空的功能内部的while可以实现，因其约束result的push_back操作，故不可省否则结果中出现空数组
            if(!stack1.empty())
            {
                vector<int> temp1;
                while(!stack1.empty())
                {
                    TreeNode *data = stack1.top();
                    stack1.pop();
                    temp1.push_back(data->val);
                    if(data->left!=NULL)
                        stack2.push(data->left);
                    if(data->right!=NULL)
                        stack2.push(data->right);

                }
                result.push_back(temp1);
            }
            if(!stack2.empty())
            {
                vector<int> temp2;        
                while(!stack2.empty())
                {
                    TreeNode *data = stack2.top();
                    stack2.pop();
                    temp2.push_back(data->val);
                    if(data->right != NULL)
                    {
                        stack1.push(data->right);
                    }
                    if(data->left != NULL)
                    {
                        stack1.push(data->left);
                    }

                }
                result.push_back(temp2);
            }      
        }
          return result;
    }

};
