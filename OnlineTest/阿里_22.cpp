#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int f(int m, int n)
{
    if(m == 1 || n == 0) return 1;
    if(m > n) return f(n, n);
    return f(n, m-1) + f(n-m, m);
}

int method(int a, int b)
{
    int j,result;
    int a1 = 0;
    int b1 = 0;
    int* store;
    int i = 0;
    store = (int*)malloc(sizeof(int));
    scanf("%d %d",&a,&b);
    *(store+i) = a;
    i++;
    *(store+i) = b;
    i++;
    while((a==a1)?((b==b1)?0:1):1){
        a1 = a;
        b1 = b;
        scanf("%d %d",&a,&b);
        *(store+i) = a;
        i++;
        *(store+i) = b;
        i++;
    }
    for(j=0;j<i-2;){
        a = *(store+j);
        j++;
        b = *(store+j);
        j++;
        result = f(a,b);
        //printf("%d\n",result);
    }

  return 0;
}

int ballAllocate(int m, int n, int k) {
	int result;
	if(m<1||n<1||k<1||m>50||n>50||k>50)
		return 0;
	if(m==1)
		result=method(n,k);
	if(n==1)
		result=method(m,k);
}

int main() {
    int res;

    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _k;
    cin >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



    res = ballAllocate(_m, _n, _k);
    cout << res << endl;

    return 0;

}
