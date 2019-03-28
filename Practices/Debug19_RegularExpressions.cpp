class Solution {
/**
�������*ʱѡ���Ƕ����Ķ��ǵ����߼�����ֹ����ķ�����Ƿȱ
�ʼǣ��ڷֽ��߼���ѡ���ϣ���ch��ȵ�������ڡ������͡�*���߼���ʹ�÷�֧���Ǹ����� 
*/
public:
    bool match(char* str, char* pattern)
    {
    	if(str == NULL || pattern == NULL)
    		return false;
    	return matchCore(str, pattern);
    }
    
    bool matchCore(char *s, char  *p)
    {
    	if(*s == '\0' && *p == '\0')
    		return true;
    	if(*s != '\0' && *p == '\0')
    		return false;
    	if(*p == '.')
    		matchCore(s+1, p+1);
    	else
    	{
    		if(*(p+1) == '*')
    			return matchCore(s+1, p+2) || matchCore(s+1, p) || matchCore(s, p+2);
    		else
    		{
    			if(*p != *s)
    				return false;
    			else
    				return matchCore(s+1, p+1);
			}
		}
		return false;
	}
};
/**
Debug:ֻ��3.33%��ͨ����
�� "" �� ".*" ��ƥ�䲻��ȥ 
*/ 
