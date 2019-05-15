class Solution {
public:
    vector<string> res;
    vector<string> Permutation(string str) {
        if(str.length()==0)
            return res;
        dfs(str,0);
        sort(res.begin(), res.end());
        //思路二：先不考虑重复，最后用unique找出重复的并erase
        //函数参考:https://blog.csdn.net/u010141928/article/details/78671603
        //res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void dfs(string str, int dep)
    {
        //debug:string类型结尾同C
        if(str[dep] == '\0')
        {
            res.push_back(str);
            return ;
        }
        for(int i = dep; i < str.length(); i++)
        {
            //思路一：在全排列的时候就避免对重复元素重复操作
            if(i!=dep && str[dep]==str[i])
                continue;
            //公有操作            
            char ch = str[i];
            str[i] = str[dep];
            str[dep] = ch;
            dfs(str, dep+1);
            ch = str[i];
            str[i] = str[dep];
            str[dep] = ch;
        }
    }
};
