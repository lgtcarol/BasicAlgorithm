//����tring����ת
int pos = str.find(' ', 0); //���ո��з�
if(pos < str.length())
{
	string s1 = str.substr(0, pos);
	string s2 = str.substr(pos+1, str.length()-pos);
	stringstream ss; //�ַ���תΪ����
	ss << s1;
	double n ;
	ss >> n;
	cout << n << endl;

	stringstream ss; //����ת�ַ���
	ss<<num;   //�����ִ�������
	string result;
	ss>>result;
}
//string��char*��ת
    string s="xiaoming";
    const char *a=s.c_str();//ȥ��const����ʾ�������
    const char *b=s.data();
    printf("a:[%s],b:[%s]\n",a,b);

//����ѭ��
for(int i = 0; i < arr.size(); i++)
{
	cout << arr[i][0] << ' ' << arr[i][1] << endl;
}

//���ȿ���
#include <iomanip>
cout.precision(2);
cout << fixed << s << endl;

//�ַ��ж�
	if(isalpha(c)) //�ж���ĸ
		cout << "c is alpha" << endl;
//	if(isalnum(c))  �ж���ĸ������
//		cout << "c is num";
	if(islower(c))
		cout << (char)toupper(c); //תΪ��д����ǿתΪchar
		cout << (char)toupper(c); //תΪ��д����ǿתΪchar
	return 0;
//����������31 18 19 1 25
int num[100];    //int���������ڴ洢�������
int i=0;
while (cin>>num[i]){
    cout<<num[i]<<" ";
    i++;
}





















