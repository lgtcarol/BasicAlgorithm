/**
(1)�ݹ���ڲ�ֹ�ں������������֣�������ݹ鴦Ҳ�������������ȥ�����յ㣨Ҫ����ʶ�ڴ˴��������벻���еĵط�����˲��ܾ�������ݹ���ѭ��ͬʱҲ��˼·���������֣�
(2)������������ṹ������˵�����ص㣩ͨ�����߼���ĵݹ����
(3)NOTE:��������������������Ѱ��������Ϣ����ϵ��Ȼ���ڽ�����Ȿ���Ŀ��Ѱ������˼·���磺��������и�������rootλ����֪�����й��ɴ��ڵ����Һ��� 
(4)!!!NOTE: �����鿴��ָ���Ǹ��ܱ�Ҫ��˼·����Ȼ�����������ṹ�йأ������˼·ֱ�ӹ�ϵ���ݹ��� 
*/
#include <cstdio>
bool VerifySquenceOfBST(int s[], int len)
{
	if(s==NULL || len<=0)
		return false;
	int r = s[len-1];
	//����qSort�Ļ���˼�룬�ֿ�ݹ���
	int i = 0;
	for(; i < len-1; i++)
	{
		if(s[i] > r)
			break;	
	} 
	//��Ȼ�˴�������һ�������ӿ�ʼ��
	int j = i;
	for(; j < len-1; j++)
	{
		if(s[j] < r)
			return false;//�����ǶԳƵĴ������˴��Ƿ���ע������	
	} 
	//�ݹ�׼��
	int len1 = i;
	int len2 = j-i;  
	return  VerifySquenceOfBST(s, len1) && VerifySquenceOfBST(s+i, len2);
	//ATTENTION:��Ȼ�ܿ�����len1��len2�ǻ�Ϊ0�ģ�������˵ݹ麯�������޷���������� 
}

// ====================���Դ���====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// ����ֻ��1�����
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", NULL, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}





















