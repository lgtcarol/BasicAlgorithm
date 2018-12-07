// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <cstdio>
/**
(1) 好的思路寻找方法加快理解 https://blog.csdn.net/yi_afly/article/details/52012593 
(2) 总体思路：从个位开始，逐位考虑该位cur带来的1个数。分两部分：(cur的高一位)round*cur_weight; 余值
    余值分两种情况：(a)大于1：cur_weight; (b)等于1：(cur的低一位)former+1(cur取1时的贡献)
(3) 思维弯子：former数并非干预了former为cur时的情况，former数累计前提是cur=1,故本质是 整轮数+对cur而言不足整轮的余值。
    但该余值不自由：若大于1自由，不大于1还要受限于更第一位。 
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
			cnt += n%cur_weight+1;  //注意此处former的求法，因每次cur_weight恰好扩大10倍
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
























































