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
//������4������
class Bag{

public:
    // 0-1�������⣺��һ����Ʒ�û��õõ�����ֵ
    void OneZeroBag(vector<Good>goods, const int W) {
        int n = goods.size();
        // d[i][j] ��ʾ��ǰ i ����0 ~ i-1����ʯ�У�ʣ�����Ϊ j �ܴﵽ������ֵ
        int **d = New2DMat(n + 1, W + 1);

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= W; j++)
            {
                d[i][j] = (i==0)?0:d[i-1][j]; //j����ʣ������
                if(i > 0 && j >= goods[i-1].weight)
                {
                    int q = d[i-1][j-goods[i-1].weight] + goods[i-1].value; // �õ� i ��
                    d[i][j] = max(d[i][j], q);//ǰ��Ϊ�������i����Ʒ������Ϊ���루���ݼ�ֵѡ���û��ã�
                }
            }
        cout << "����ֵ��" << d[n][W] << endl;
        // ���ѡ����
        cout << "������Ʒ��ţ�"; //���֪����������Щ��Ʒ�����õ�һ�����ú���ֵ�����˵�λ��
        int j = W;
        for (int i = n; i > 0; i--) {
            if (d[i][j] > d[i - 1][j]) {
                j -= goods[i - 1].weight; //ע��˴�
                cout << goods[i - 1].num << " ";
            }
        }

        cout << endl;
    }
    // �����������⣺������Ʒ���Ա��ָ����������-->�õ�����������
    void FractionalBag(vector<Good> &goods, const int W) {
        SortGood(goods, 0, goods.size() - 1); // ����λ��ֵ�Ӹߵ�������
       //sort(goods.begin(), goods.end(), cmp);
        int m = 0;
        for(int i = 0; i < goods.size(); i++)
        {
            int take_weight = min(goods[i].weight, W-m); //���ִ���������ʣ����������ʣ����������
            cout << "������Ʒ" << goods[i].num << "��������" << take_weight << endl;
            m += take_weight;
            if(m == W) //���ֱ��������ǿ����õ�ȫ�������ģ�
                break;
        }
    }

private:
//    bool cmp(Good &a, Good &b)
//    {
//        return a.unit_value > b.unit_value; //����
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
    Good g1(1, 5, 20); //��Ʒ��ţ���������ֵ
    Good g2(2, 4, 10);
    Good g3(3, 3, 12);
    Good good_array[] = { g1, g2, g3 };
    vector<Good> goods(good_array, good_array+3); //����3����Ʒ�ಢ���뵽vector��
    const int W = 10; //��������
    Bag bag; //��������������

    cout << "�����������⣺" << endl;
    bag.FractionalBag(goods, W);

    cout << "0-1 �������⣨�û��ã���" << endl;
    bag.OneZeroBag(goods, W);
}
