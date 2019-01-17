// ������65�����üӼ��˳����ӷ�
// ��Ŀ��дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�ã�������������
// ����������š�

#include <cstdio>

int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2; //lgt:�����ǽ�λ�ĸ�λ�ۼ� 
        carry = (num1 & num2) << 1; // lgt: ͨ���ܽ��ۼ��в�����λ���߼����������ֵ�·����ֵ�������������һ��ζ 

        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);//NOTE:��ȡ�Ľ�λcarry����Ϊѭ�����������ִ���ѵ������������
	//lgt��𣺵�һ��carry�߼�����û������Ȼ�ڵڶ���ѭ����sum���ʱֻ��ԭ��Ϊ1��λ����Ӱ�죬�Ҹý�λ��ҲΪ1�Ż����һ�ν�λ����������߼�ȥ���ǵ���˭��Ӱ�죩 

    return num1;
}

// ====================���Դ���====================
void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

int main(int argc, char* argv[])
{
    Test(1, 2, 3);
    Test(111, 899, 1010);

    Test(-1, 2, 1);
    Test(1, -2, -1);

    Test(3, 0, 3);
    Test(0, -4, -4);

    Test(-2, -8, -10);

    return 0;
}
