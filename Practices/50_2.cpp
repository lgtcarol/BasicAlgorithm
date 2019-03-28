/**
开心的一逼：根据错误案例的反馈完美AC! 
笔记：C++类中变量的初始化问题，构造函数public且在其中申请空间和初始化。 
	  队列：解决先出现的问题，从而避免50_1对此采取的遍历str操作
	  book: 依据按照char进行哈希记录出现次数 
*/

class Solution
{
	vector<int> book;
	queue<char> q;

public:
    Solution()  
    {
        book.resize(256);
        for(int i = 0; i < 256; ++i)
            book[i] = -1; //标空 
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        int index = (int)ch;
        if(book[index] == -1)
		{
        	book[index] = 1;
    		q.push(ch);       	//！符合条件的才入队列 
		}
        else
        	book[index] += 1;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	char res = '#';
    	while(!q.empty())
    	{
    		char ch = q.front();
    		if(book[(int)ch] == 1)
    			return ch;
    		else
    			q.pop();
		}
		return res;
    }

};
