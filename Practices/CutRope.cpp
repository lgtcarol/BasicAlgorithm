/**
Debug: �����������Ž��¼�������У�arr[2] = 2, ����1
*/

class Solution {
public:
    int integerBreak(int n) 
    {
        
        //�������Ž������ڸ�����������Ž⣬��̬�滮
		//�Ե����ϵݹ飬���壺i*(n-i) �ͣ�n-i��*i��ͬ 
		//���ȣ������������Ž����⣬��Σ����������С���⣬���Ҵ���������Ž������С��������Ž⣬���Կ���ʹ�ö�̬�滮������⣬���Ҵ�С������⣬��С��������Ž��¼�������У�����������Ž�ʱ�Ϳ���ֱ�ӻ�ȡ�������ظ����㡣 
		
		//�ɽ�������ֱ�ӷ���
		if(n == 2) 
			return 1;
		if(n == 3)
			return 2;
		//��������洢����������Ž�
		int* arr = new int[n+1];
        int max = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		for(int i = 4; i <= n; i++)
		{
			max = 0;
			for(int j = 1; j <= i/2; j++)
			{
				int product  = arr[j]*arr[i-j];
				if(product > max)
					max = product; 
                //�ǵý�������õ������������Ž���м�¼
                arr[i] = max;
			}
		}   
       // max = arr[n];
        delete[] arr;
		return max;
    }    
};

/**
̰���㷨������ѧ�е�Ҫ�� 
��n>=5ʱ��2(n-2)>n��3(n-3)>n�������˵�������Ӽ���2��(n-2)���߼���3��(n-3)ʱ���˻����ڲ����ĳ˻���
�����Ҫ�����Ӽ���2����3.����3�˻��������ȼ�3������1����һ��3��Ϊ����2������2���2ֱ����Ϊ���� 
*/
class Solution{
public:
	int integerBreak(int n )
	{
		if(n <2)
			return 0;
		if(n == 2) 
			return 1;
		if(n == 3)
			return 2;
			
		int numOf3 = n/3;
		if(n%3 == 1)
		{
			numOf3 -= 1; 
		}
		int numOf2 = (n-numOf3*3)/2;
		return pow(3, numOf3)*pow(2, numOf2);
	}
}; 















