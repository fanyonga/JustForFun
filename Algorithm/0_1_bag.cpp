#include<iostream>
using namespace std;

int findM(int size, int goods_num, int good_size[], int good_value[])
{
    int *M = new int[size + 1], i, j;
    for(i = 0; i < size + 2; i ++)
        M[i] = 0;
    for(i = 0; i < goods_num; i ++)
        for(j = size; j >= good_size[i]; j --)
            //for(k = 1; j - k * good_size[i] >= 0;k ++)
                //M[j] = M[j] > k * good_value[ i ] + M[j - k * good_size[i]] ? M[j] : k * good_value[ i ] + M[j - k * good_size[i]];
            M[j] = M[j] > good_value[i] + M[j - good_size[i]] ? M[j]: good_value[i] + M[j - good_size[i]];
    return M[size];
}

int main()
{
    int size, goods_num, i;
    cout<<"请输入背包大小、货物种类数\n";
    cin>>size>>goods_num;
    int *good_size = new int[goods_num];
    int *good_value = new int[goods_num];
    for(i = 0; i < goods_num; i ++)
    {
        cout<<"请输入第"<<i + 1<<"个物品的大小和价值\n";
        cin>>good_size[i]>>good_value[i];
    }
    cout<<"最大价值总和为：\n";
    cout<<findM(size, goods_num, good_size, good_value)<<endl;
    delete [] good_size;
    delete [] good_value;
    return 0;
}

