/**
������̰��
����˵������ֱ������⣬�����ݾ�����̾�����0-1�������е����⡣��
*/

#include <iostream>
using namespace std;

struct Node
{
    float weight; //����
    float value; //��ֵ
    bool mark; //�Ƿ�װ��
    char char_mark; ////��Ӧ����Ʒ����
    float pre_weight_value; //��λ����
};

int main(int argc, char* argv[])
{
    float Weight[7] = {35,30,60,50,40,15,20};
    float Value [7] = {10,40,30,50,35,40,30};
    Node things[7];
    for(int i=0; i<7; i++) //��Ʒ��Ϣ�ĳ�ʼ��
    {
        things[i].value = Value[i];
        things[i].weight = Weight[i];
        things[i].char_mark = 65 + i;
        things[i].mark = false;
        things[i].pre_weight_value = Value[i] / Weight[i];
    }
//��λ��Ʒ�ļ�ֵ�鿴
//    for(i=0;i<7;i++)
//        cout<<array[i].pre_weight_value<<" ";
//    cout<<endl;

    float weight_all=0.0;
    float value_all = 0.0;
    float maxV = 0.0;
    char res[7]; //
    int flag,n = 0;

    while(weight_all <= 150) //����������150�����µ���Ʒ������������Ҫÿ����Ʒ��mark��ǣ�
    {
        for(int index = 0; index<7; index++)
        {
            if(things[index].pre_weight_value > maxV && things[index].mark == false)//����ұ��ֵ�����ֵ������ѡ�������е���ѭ��
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
                flag = i; //��ѡ��
            }
        }//���������ҵ����ѡ��
        //���ּ�¼�޸ĺͼ�����
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
