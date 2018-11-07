#include<cstdio>
#include<stdlib.h> 
#include <stdexcept>
using namespace std; 
//给定先序和中序，建立二叉树 
struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};
TreeNode* ConstructCore(int *prestart, int *preend, int *instart, int *inend);
void PrintTree(TreeNode* root);
TreeNode* Construct(int pre[], int in[], int len)
{
	//输入检查！ 除了是代码性的合理检查，还有传入参数的逻辑合理性检查！如根本无法完成题目要求 
	if(pre==NULL || in==NULL || len==0)
		return NULL;
	//之所以分成两部分是为了递归结构。 
	return ConstructCore(&pre[0], &pre[len-1], &in[0], &in[len-1]);//再次证明数组和指针的关系，重点是长度给了即可	 
 } 
TreeNode *ConstructCore(int *prestart, int *preend, int *instart, int *inend)
{
	TreeNode *root = new TreeNode();
	root->value = *prestart;
	root->left = NULL;
	root->right = NULL;
	//确定递归长度
	int r =  *prestart;
	int *p = NULL;
	for(p = instart; p <= inend; p++) //显然前提是前序和中序中数字不存在重复 
		if(*p == r)
			break;//p指向中序数组中的root
	if(p > inend)
//		throw std::exception("Invalid input.");不知道为何用不了 
	{
		printf("请检查所给序列是否成立！\n");
		exit(1);
	} 
	int leftlen = p-instart;
	int rightlen = inend-p;
	if(leftlen > 0)
		root->left = ConstructCore(prestart+1, prestart+leftlen, instart, p-1);
	if(rightlen > 0)
		root->right = ConstructCore(prestart+leftlen+1, preend, p+1, inend);
	//错误：未考虑所给数组不能建立二叉树的异常情况 
	return root; 
}
void PrintTree(TreeNode* root)
{
	if(root != NULL)
	{
		PrintTree(root->left);
		printf("%d\t", root->value);
		PrintTree(root->right);
	}
}
int main(void)
{
	int pre[] = {1, 2, 4, 5, 3, 6, 7};
	int in[] = {4, 2, 8, 1, 6, 3, 7};
	TreeNode *tree = Construct( pre, in, 7); 
	PrintTree(tree);
	return 0;
}
