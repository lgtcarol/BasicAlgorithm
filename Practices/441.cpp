int arrangeCoins(int n) {
    int count = 0;
    for(long i = 1;n > 0;i++)
        if(n >= i)
        {
            count++;
            n = n - i;
        }
        else break;
    return count;
}
