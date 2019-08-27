#include<sstream>
#include<string>
#include<iostream>
using namespace std;
//int main(){
//    string line;
//    //读入一行由【空格】隔开的【数组】,或者【字符串数组】
//    while(getline(cin,line)){
//       // int x;
//        string x;
//        stringstream ss(line);  //建立stringstream对象，初始化流内容为line所代表的字符串
//        while(ss>>x)            //从line中一次读取数字存入x
//            cout<<x<<endl;
//    }
//    return 0;
//}

//读入一行由【任意分隔符】隔开的【数组】,或者【字符串数组】
int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss(s);
        string tmp;
        //stringstream结合getline实现了对字符串split的功能
        while(getline(ss,tmp,','))
            cout << tmp << endl;

    }
    return 0;
}

