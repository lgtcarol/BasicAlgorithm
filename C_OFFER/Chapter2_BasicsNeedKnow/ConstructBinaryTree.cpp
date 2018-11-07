#include<cstdio>
#include<stdlib.h> 
#include <stdexcept>
using namespace std; 
//������������򣬽��������� 
struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};
TreeNode* ConstructCore(int *prestart, int *preend, int *instart, int *inend);
void PrintTree(TreeNode* root);
TreeNode* Construct(int pre[], int in[], int len)
{
	//�����飡 �����Ǵ����Եĺ����飬���д���������߼������Լ�飡������޷������ĿҪ�� 
	if(pre==NULL || in==NULL || len==0)
		return NULL;
	//֮���Էֳ���������Ϊ�˵ݹ�ṹ�� 
	return ConstructCore(&pre[0], &pre[len-1], &in[0], &in[len-1]);//�ٴ�֤�������ָ��Ĺ�ϵ���ص��ǳ��ȸ��˼���	 
 } 
TreeNode *ConstructCore(int *prestart, int *preend, int *instart, int *inend)
{
	TreeNode *root = new TreeNode();
	root->value = *prestart;
	root->left = NULL;
	root->right = NULL;
	//ȷ���ݹ鳤��
	int r =  *prestart;
	int *p = NULL;
	for(p = instart; p <= inend; p++) //��Ȼǰ����ǰ������������ֲ������ظ� 
		if(*p == r)
			break;//pָ�����������е�root
	if(p > inend)
//		throw std::exception("Invalid input.");��֪��Ϊ���ò��� 
	{
		printf("�������������Ƿ������\n");
		exit(1);
	} 
	int leftlen = p-instart;
	int rightlen = inend-p;
	if(leftlen > 0)
		root->left = ConstructCore(prestart+1, prestart+leftlen, instart, p-1);
	if(rightlen > 0)
		root->right = ConstructCore(prestart+leftlen+1, preend, p+1, inend);
	//����δ�����������鲻�ܽ������������쳣��� 
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
