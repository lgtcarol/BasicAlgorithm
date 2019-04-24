/**
方法：贪心
按理说解决部分背包问题，但根据抉择过程觉得是0-1背包，有点问题。。
*/

#include <iostream>
using namespace std;

struct Node
{
    float weight; //重量
    float value; //价值
    bool mark; //是否被装入
    char char_mark; ////对应的物品名称
    float pre_weight_value; //单位重量
};

int main(int argc, char* argv[])
{
    float Weight[7] = {35,30,60,50,40,15,20};
    float Value [7] = {10,40,30,50,35,40,30};
    Node things[7];
    for(int i=0; i<7; i++) //物品信息的初始化
    {
        things[i].value = Value[i];
        things[i].weight = Weight[i];
        things[i].char_mark = 65 + i;
        things[i].mark = false;
        things[i].pre_weight_value = Value[i] / Weight[i];
    }
//单位物品的价值查看
//    for(i=0;i<7;i++)
//        cout<<array[i].pre_weight_value<<" ";
//    cout<<endl;

    float weight_all=0.0;
    float value_all = 0.0;
    float maxV = 0.0;
    char res[7]; //
    int flag,n = 0;

    while(weight_all <= 150) //总重量不超150条件下的物品遍历，所以需要每个物品的mark标记！
    {
        for(int index = 0; index<7; index++)
        {
            if(things[index].pre_weight_value > maxV && things[index].mark == false)//如何找本轮的最大价值？类似选择排序中的内循环
            {
                maxV = things[index].pre_weight_value;
                flag = index;
            }
        }
        for(int i = 0; i < 7; i++)
        {
            if(things[i].pre_weight_value > maxV && things[i].mark == false)
            {
                maxV = things[i].pre_weight_value;
                flag = i; //候选人
            }
        }//遍历结束找到最佳选择
        //本轮记录修改和加入结果
        res[n++] = things[flag].char_mark;
        things[flag].mark = true;
        weight_all+=things[flag].weight;
        value_all += things[flag].value;
        maxV = 0.0;
    }
    int i ;
    for(i=0;i<n-1;i++)
        cout<<res[i]<<" ";
    cout<<endl;
    cout<<"weight_all:"<<weight_all- things[n-1].weight<<endl;
    cout<<"value_all:"<<value_all<<endl;

  //  system("pause");
    return 0;
}
