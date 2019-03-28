class Solution {
/**
错因：面对*时选择是多样的而非单线逻辑；终止情况的分析有欠缺
笔记：在分界逻辑的选择上，将ch相等的情况放在‘。’和‘*’逻辑下使得分支考虑更有序 
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
Debug:只有3.33%的通过率
如 "" 和 ".*" 就匹配不过去 
*/ 
