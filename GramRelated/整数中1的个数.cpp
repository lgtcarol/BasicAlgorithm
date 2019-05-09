class Solution {
public:
    /**
    思路一：整数右移&1,缺点是对于负数如0x80000000右移后不为0x40000000,而为0xC0000000
    因右移后要保证负数本质。
     int  NumberOf1(int n) {
         int base = 1;
         int cnt = 0;
         while(n)
         {
             if(n & 1)
                cnt++;
             n = n >> 1;
         }
     }    
    */
    //思路二：数不右移，而是用1左移与该数相&
    int numberof2(int n)
    {
        int cnt = 0;
        unsigned int flag = 1;
        while(flag)//其实不用担心该循环不终止，因unsigned类型也就32个bit
        {
            if(n & flag)
                cnt++;
            flag = flag << 1;
        }
        return cnt;
    }
    //思路三:把一个整数减去1，再和原整数&，会把该数最右边的一个1变成0，那么该整数二进制中有多少个1则可进行多少这种操作。
    int numberof3(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
