// ������43����1��n������1���ֵĴ���
// ��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���������
// ����12����1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

#include <cstdio>
/**
(1) �õ�˼·Ѱ�ҷ����ӿ���� https://blog.csdn.net/yi_afly/article/details/52012593 
(2) ����˼·���Ӹ�λ��ʼ����λ���Ǹ�λcur������1�������������֣�(cur�ĸ�һλ)round*cur_weight; ��ֵ
    ��ֵ�����������(a)����1��cur_weight; (b)����1��(cur�ĵ�һλ)former+1(curȡ1ʱ�Ĺ���)
(3) ˼ά���ӣ�former�����Ǹ�Ԥ��formerΪcurʱ�������former���ۼ�ǰ����cur=1,�ʱ����� ������+��cur���Բ������ֵ���ֵ��
    ������ֵ�����ɣ�������1���ɣ�������1��Ҫ�����ڸ���һλ�� 
*/

int count(int n)
{
	if(n < 1)
		return  0;
	int cnt = 0, round = n;
	int cur_weight = 1;
	while(round > 0)
	{
		int cur = round%10;
		round = round/10;
		cnt += round * cur_weight;
		if(cur > 1)
			cnt += cur_weight;
		if(cur == 1)
			cnt += n%cur_weight+1;  //ע��˴�former���󷨣���ÿ��cur_weightǡ������10��
		cur_weight *= 10; 
	}
	return cnt;
} 

int main(int argc, char* argv[])
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 2)
			break;
			
		printf("%d: %d\n", n, count(n));	
	} 
	return 0;
}
























































