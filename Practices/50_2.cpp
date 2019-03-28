/**
���ĵ�һ�ƣ����ݴ������ķ�������AC! 
�ʼǣ�C++���б����ĳ�ʼ�����⣬���캯��public������������ռ�ͳ�ʼ���� 
	  ���У�����ȳ��ֵ����⣬�Ӷ�����50_1�Դ˲�ȡ�ı���str����
	  book: ���ݰ���char���й�ϣ��¼���ִ��� 
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
            book[i] = -1; //��� 
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        int index = (int)ch;
        if(book[index] == -1)
		{
        	book[index] = 1;
    		q.push(ch);       	//�����������Ĳ������ 
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
