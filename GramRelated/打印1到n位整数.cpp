//n位数申请的char空间为n+1
void printOneToMax(int n)
{
    if(n < 0)
        return;
    char *number = new char[n+1];
//因为每位操作一模一样，所以可以用递归。当位每枚举一个值，便深入一位故dfs。
    dfs(number, n, 0);
    delete[] number;
}
void dfs(char *number, int length, int index)
{
    if(index == length)
    {
        //注意打印字符串整数时的0出现位置.
        PrintNumber(number);
        return ;
    }
    //不就是一个枚举过程么
    for(int i = 0; i < 10; ++i)
    {
        number[index] = i+'0';
        number(number, length, index+1);
    }

}
void PrintNumber(char *number)
{
    bool flag = false;
    for(int i = 0; i < strlen(number); i++)
    {
        if(!flag && number[i]!='0')
            flag =true;
        if(flag)
            printf("%c", number[i]);
    }
}

