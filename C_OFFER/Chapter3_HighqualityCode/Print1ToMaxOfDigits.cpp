// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#include <cstdio>
#include <cmath>
#include <cstring>
void Print1ToMaxOfNDigits(int n);
void Print1ToMaxOfNDigits_1(int n);
bool Increment(char *num);
void Print1ToMaxOfNDigits_2(int n);
void Print1ToMaxNDigitsRecursively(char *num, int n, int index);
void PrintNumber(char *num);

void Print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
		return;
	//�����뷨��������λn���ɳ�����������ѭ���ۼӴ�ӡ����
	long long num = pow(10,n);
	for(long long i = 0; i < num; i++)
		printf("%lld \t", i);
}
//��Ȼ4�ֽ�intҲֻ��21�ڣ���n=10�������Ⲣδ˵n�ķ�Χ
//����˼ά���壺���������⣡

void Print1ToMaxOfNDigits_1(int n)
{
	if(n <= 0)
		return;
	char *num = new char[n+1];//�ַ���������־
	memset(num, '0', n);//����ռ��ĳ�ʼ�������� 
	num[n] = '\0';
	
	//Notes:��ʵ�����������Ͳ���number�У�Increment()�����ľ��Ǽ�һ����ͨ��number���ظı䡣
	//����whileѭ���ڲ���ÿ����һ�η���һ��boolֵ�� 
	while(!Increment(num))
	{
		PrintNumber(num);
	} 
	delete []num;
} 

bool Increment(char *num)
{
	//�ӱ��������Ŀ����������Ҫ֪����ʱ��ӡ��ϣ������ʵ���nλ��
	bool isOverflow = false; 
	//ģ�����������Ӳ�����λ��λ����ӡ1~10^n���������ۼӽ�λ���� 
	//Ϊ���ڽ�λֱ�Ӳ������㣬��Ϊint����
	int nTakeOver = 0;
	int len = strlen(num);
	for(int i = len-1; i >= 0; i--)
	{
		int nSum = num[i] - '0' + nTakeOver;
		if(i == len-1)
			nSum++;//��λ��һ�����ǽ�һ�Σ�
		//Notes:�ǵģ����������ǵݹ飬��ÿ���øú���һ�α�ʵ��һ�μ�һ�������ָı�ͨ�����ò������� 
		//�������غ��whileѭ����ʵ�ֶ��������ֱ��ĳ�ε��ú�������false����ֹ�ú����ĵ��ü���ֹ��һ����
		//while(f())�ṹ��f()����falseʱ���Ƶݹ麯���ĳ���һ�� 
		
		//Notes:����Ϊ��ʵ������������һ�������ڸ�λ��һ��
		//Notes:��ͨ��stringʵ��int���⣬����νӣ�������'0'+��ֵ 
		if(nSum >= 10)
		{
			if(i == 0){ 
				isOverflow = true;
				break; 
			} 
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				num[i] = '0' + nSum; 
			}
		} 
		else
		{
			//���û�н�λ�ǿ���ֱ�ӽ�����һ���̵ģ�������break 
			num[i] = '0' + nSum;
			break;
		}
	}
	 return isOverflow; 
}
void Print1ToMaxOfNDigits_2(int n)
{
	if( n <= 0)
		return;
	char *num = new char[n+1];
	memset(num, '0', n);
	num[n] = '\0';
	for(int i =0; i < 10 ;i++)
	{
		num[0] = i + '0';//�оٵ��������±�0����� 
		Print1ToMaxNDigitsRecursively(num, n, 0); //�ݹ��о��±�Ϊ0+1����� 
	}
}
void Print1ToMaxNDigitsRecursively(char *num, int n, int index)
{
	printf("start of program ,index: %d \n",index);
	if(index == n-1)//nλ��������±굽n-1 
	{
		//������¶��ϵ�ʵ�ַ�ʽ���ݹ��ջ���ԣ�λ���ٵ����ȴ�ӡ
		printf("begin return\t");
	//	num[index] = '\0'; 
		PrintNumber(num);
		return;	
	} 
	for(int i =0; i < 10 ;i++)
	{
		num[index+1] = i + '0';
//		printf("index:%d, %c ", index, num[index]); 
		Print1ToMaxNDigitsRecursively(num, n, index+1);
	}
}


void PrintNumber(char *num)
{
	bool start = false;
	int len = strlen(num);
//	printf("hello\n");
	for(int i = 0; i < len; i++)
	{
		if( num[i]!='0' && start==false )
			start = true;//��ʼ��ӡ 
		if(start == true)
			printf("%c", num[i]);
	}
	printf("\t");
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

  //  Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
/**
solution1:���ж������ֻ������flagֵȴ��������ѭ��������ע��ÿ�����������������
solution2:��������������˼·����ǰ����ö�ٶ�Ӧ��index�͵ݹ���õ�index����ͬ�ģ���������Ϊ��index��index+1��ϵ����
(1)����Ϊ��index+1�������һ����ֱ�ӿ�ʼ��ӡ����ȱ�ٸ�λ�ı���.��n=2ʱ����ֻ�ܴ�ӡ��10-90��ȱ�ٶԸ�λ�ı���
(2)����������ѭ������Ϊѭ����������߼�����(���������ȫ)����n=1ʱ��index-1=0��ʼ�˳�����������ƽ���������Сindex=1,��Զȡ����0��������Զ�޷��˳���

(3)�ݹ������ƻ���Ҫ��Ϥ��������Щ��ӡ�Ľ����Ϥ�ݹ飡 
*/














