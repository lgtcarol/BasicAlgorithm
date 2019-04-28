//解法一：二维辅助数组
int getMaxValue_solution1(const int* values, int rows, int cols)
{
    if(values == NULL || rows <= 0 || cols <= 0)
        return 0;

    //二维空间申请
    int **maxValues = new int*[rows];
    for(int i = 0; i < rows; ++i)
        maxValues[i] = new int[cols];

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[i - 1][j];

            if(j > 0)
                left = maxValues[i][j - 1];
            //不存在边界值初始化问题，初始值为0即可，起始步的值即为起始格子的礼物值
            maxValues[i][j] = std::max(left, up) + values[i * cols + j];
        }
    }
    int maxValue = maxValues[rows - 1][cols - 1]; //右下角的值即为最优值

    //二维空间释放
    for(int i = 0; i < rows; ++i)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValue;
}
//思路二：一维辅助数组（重点就是分析出每次计算新的(i,j)时，使用数组下标j-1和j的最大值加当前礼物值即可。）
int getMaxValue_solution2(const int* values, int rows, int cols)
{
    if(values == NULL || rows <= 0 || cols <= 0)
        return 0;

    int* maxValues = new int[cols];
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[j];

            if(j > 0)
                left = maxValues[j - 1];

            maxValues[j] = std::max(left, up) + values[i * cols + j];
        }
    }

    int maxValue = maxValues[cols - 1];

    delete[] maxValues;

    return maxValue;
}
