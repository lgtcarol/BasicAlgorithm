class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        if(threshold<1 || rows<1 || cols<1)
        {
            return count;
        }
        bool *visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        count = movingCount(threshold,rows, cols, 0, 0, visited);
        delete[] visited;
        return count ;
    }

    int movingCount(int threshold, int rows, int cols, int row, int col, bool *visited)
    {
        int count = 0;
        if(row >= 0 && row < rows && col >=0 && col<cols && getDigitSum(row)+getDigitSum(col)<=threshold && !visited[row*cols+col])
        {
            visited[row*cols+col] = true;
            count = 1++ movingCountCore(threshold, rows, cols, row-1, col, visited)+movingCountCore(threshold, rows, cols, row+1, col, visited)+\
		movingCountCore(threshold, rows, cols, row, col-1, visited)+movingCountCore(threshold, rows, cols, row, col+1, visited);
        }
        return count;
    }
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num%10;
            nuum /= 10;
        }
        return sum;
    }
};
