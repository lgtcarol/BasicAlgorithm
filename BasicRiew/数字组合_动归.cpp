#include <iostream>
#include <cmath>
using namespace std;
int partion(int *myarr, int l, int h)
{
    int pis = myarr[l];
    while(l < h)
    {
        while(l < h && myarr[h] > pis)
            h--;
        myarr[l] = myarr[h];
        while(l < h && myarr[l] <= pis)
            l++;
        myarr[h] = myarr[l];
    }
    myarr[l] = pis;
    return l;
}
void qSort(int *myarr, int l, int h)
{
    if(l<h)
    {
        int pivot = partion(myarr, l, h);
        qSort(myarr, l, pivot-1);
        qSort(myarr, pivot+1, h);
    }
}
bool compare(int Num1,int Num2);
int main(int argc, char* argv[])
{
    //预处理之数据输入读取
    int N;
    cout<<"please enter the number n:"<<endl;
    cin>>N;
    int *myarr = new int [N];
    for(int i=0;i<N;i++)
        cin >> myarr[i];
    //贪心法则：对数组降序排序（采用我的快排..）
    qSort(myarr, 0, N-1);
//    int temp;
//    for(int i=0; i<=N-1 ; ++i)
//    {
//        for(int j=0;j<N-i-1;j++)
//            if( compare(array[j],array[j+1]) )
//            {
//                temp = array[j];
//                array[j] = array[j+1];
//                array[j+1] = temp;
//            }
//    }
    cout<<"the max number is:";
    for(int i=N-1 ; i>=0 ; --i)
        cout<<myarr[i];
    cout << endl;
    delete [] myarr;
    //system("pause");
    return 0;
}

bool compare(int Num1,int Num2)
{
    int count1=0,count2=0;
    int MidNum1 = Num1,MidNum2 = Num2;
    while( MidNum1 )
    {
        ++count1;
        MidNum1 /= 10;
    }

    while( MidNum2 )
    {
        ++count2;
        MidNum2 /= 10;
    }

    int a = Num1 * pow(10,count2) + Num2;
    int b = Num2 * pow(10,count1) + Num1;

    return (a>b)? true:false;
}












