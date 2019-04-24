#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Good {
public:
    int num;
    int weight;
    int value;
    float unit_value;
    Good(int n, int w, int v) : num(n), weight(w), value(v) {
        if (w == 0) unit_value = 0;
        else    unit_value = (float)v / (float)w;
    };
};
//该类有4个方法
class Bag{

public:
    // 0-1背包问题：对一件物品拿或不拿得到最大价值
    void OneZeroBag(vector<Good>goods, const int W) {
        int n = goods.size();
        // d[i][j] 表示在前 i 个（0 ~ i-1）宝石中，剩余体积为 j 能达到的最大价值
        int **d = New2DMat(n + 1, W + 1);

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= W; j++)
            {
                d[i][j] = (i==0)?0:d[i-1][j]; //j代表剩余容量
                if(i > 0 && j >= goods[i-1].weight)
                {
                    int q = d[i-1][j-goods[i-1].weight] + goods[i-1].value; // 拿第 i 个
                    d[i][j] = max(d[i][j], q);//前者为不放入第i件物品，后者为放入（根据价值选择拿或不拿）
                }
            }
        cout << "最大价值：" << d[n][W] << endl;
        // 输出选择结果
        cout << "所拿商品编号："; //如何知道你拿了哪些物品，你拿的一定是让函数值增大了的位置
        int j = W;
        for (int i = n; i > 0; i--) {
            if (d[i][j] > d[i - 1][j]) {
                j -= goods[i - 1].weight; //注意此处
                cout << goods[i - 1].num << " ";
            }
        }

        cout << endl;
    }
    // 分数背包问题：假设物品可以被分割（两步：排序-->拿到满足重量）
    void FractionalBag(vector<Good> &goods, const int W) {
        SortGood(goods, 0, goods.size() - 1); // 按单位价值从高到低排序
       //sort(goods.begin(), goods.end(), cmp);
        int m = 0;
        for(int i = 0; i < goods.size(); i++)
        {
            int take_weight = min(goods[i].weight, W-m); //部分处理：若超过剩余质量，拿剩余质量即可
            cout << "拿走商品" << goods[i].num << "的重量是" << take_weight << endl;
            m += take_weight;
            if(m == W) //部分背包问题是可以拿到全部重量的！
                break;
        }
    }

private:
//    bool cmp(Good &a, Good &b)
//    {
//        return a.unit_value > b.unit_value; //降序
//    }

    void SortGood(vector<Good> &goods, int l, int r) {
        if (l >= r)
            return;
        int m = (l + r) / 2;
        SortGood(goods, l, m);
        SortGood(goods, m + 1, r);
        MergeAB(goods, l, m, r);
    }

    void MergeAB(vector<Good> &goods, int l, int m, int r) {
        vector<Good>temp;
        int i, j, k;
        for (i = l; i <= m; i++)
            temp.push_back(goods[i]);
        for (j = r; j > m; j--)
            temp.push_back(goods[j]);
        i = l, j = r;
        k = l;
        while (i <= j) {
            if (temp[i].unit_value > temp[j].unit_value)
                goods[k++] = temp[i++];
            else
                goods[k++] = temp[j--];
        }
    }
    int** New2DMat(int row, int col) {
        int **Mat = new int*[row];
        for (int i = 0; i < row; i++)
            Mat[i] = new int[col];
        return Mat;
    }
//    vector<vector <int> > New2DMat(int row, int col)
//    {
//        vector<vector <int> > mat(row);
//        for(int i = 0; i < row; i ++)
//        {
//            vector<int> tmp(col);
//            mat[i].push_back(tmp);
//        }
//    }
};
int main()
{
    Good g1(1, 5, 20); //物品编号，重量，价值
    Good g2(2, 4, 10);
    Good g3(3, 3, 12);
    Good good_array[] = { g1, g2, g3 };
    vector<Good> goods(good_array, good_array+3); //生成3个物品类并加入到vector中
    const int W = 10; //限制条件
    Bag bag; //创建背包问题类

    cout << "分数背包问题：" << endl;
    bag.FractionalBag(goods, W);

    cout << "0-1 背包问题（拿或不拿）：" << endl;
    bag.OneZeroBag(goods, W);
}
