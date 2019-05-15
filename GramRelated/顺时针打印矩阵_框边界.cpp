class Solution {
public:
        vector<int> printMatrix(vector<vector<int> > matrix)
        {
            vector<int> ret;
            int r1=0, rr=matrix.size()-1;//提前计算好最外圈的行号和列号
            int c1 = 0, cr=matrix[0].size()-1;//毫无悬念：边界值正好是每次遍历时不动的位置
            while(r1<=rr && c1<=cr)
            {
                for(int i = c1; i <= cr; i++)//列变
                    ret.push_back(matrix[r1][i]);
                for(int i = r1+1; i <= rr; i++ )//行变
                    ret.push_back(matrix[i][cr]);
                if(r1 != rr)//往左走(本质是打行)前提是不同行，否则重复打印了
                    for(int i = cr-1; i >= c1; i--)//列变
                        ret.push_back(matrix[rr][i]);
                if(c1 != cr)//往上走（本质是打印列）前提是有新列
                    for(int j = rr-1; j > r1; j--)//行变
                        ret.push_back(matrix[j][r1]);
                r1++;
                c1++;
                rr--;
                cr--;
            }
            return ret;
        }
};
