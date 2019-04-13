//数字tring串互转
int pos = str.find(' ', 0); //按空格切分
if(pos < str.length())
{
	string s1 = str.substr(0, pos);
	string s2 = str.substr(pos+1, str.length()-pos);
	stringstream ss; //字符串转为数字
	ss << s1;
	double n ;
	ss >> n;
	cout << n << endl;

	stringstream ss; //数字转字符串
	ss<<num;   //将数字传入流中
	string result;
	ss>>result;
}
//string和char*互转
    string s="xiaoming";
    const char *a=s.c_str();//去掉const会显示编译错误
    const char *b=s.data();
    printf("a:[%s],b:[%s]\n",a,b);

//常用循环
for(int i = 0; i < arr.size(); i++)
{
	cout << arr[i][0] << ' ' << arr[i][1] << endl;
}

//精度控制
#include <iomanip>
cout.precision(2);
cout << fixed << s << endl;

//字符判断
	if(isalpha(c)) //判断字母
		cout << "c is alpha" << endl;
//	if(isalnum(c))  判断字母或数字
//		cout << "c is num";
	if(islower(c))
		cout << (char)toupper(c); //转为大写后需强转为char
		cout << (char)toupper(c); //转为大写后需强转为char
	return 0;
//输入样例：31 18 19 1 25
int num[100];    //int型数组用于存储输入变量
int i=0;
while (cin>>num[i]){
    cout<<num[i]<<" ";
    i++;
}
//字符串转置（string 和 非string）
#include <algorithm>
reverse(s.begin(), s.end());
#include <cstring>
strrev(s);





















