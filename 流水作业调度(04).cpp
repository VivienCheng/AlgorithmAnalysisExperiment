#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 8;

struct node{
    int time_; //执行时间
    int index_; //作业序号
    bool group_; // 作业所属组 1为第一组 0为第二组
    bool operator < (const node& a)
    {
        return time_ < a.time_;
    }
};

bool cmp(const node& a,const node& b)
{
    return a.time_ < b.time_;
}

int a[maxn],b[maxn],c[maxn];//a记录在M1机器上工作时间,b记录在M2上工作时间,c记录最优调度序列
int num;//作业数

void Init()
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
}
void Input()
{
    scanf("%d",&num);
    for(int i = 0; i < num; ++i){ scanf("%d",&a[i]);}
    for(int i = 0; i < num; ++i){ scanf("%d",&b[i]);}
}

int FlowShop(int a[], int b[], int c[])
{
    node* d = new node[num + 2];
    for(int i = 0; i < num; ++i)
    {
        d[i].time_ = a[i] <= b[i] ? a[i] : b[i];//执行时间
        d[i].group_ = a[i] <= b[i];//1为第一组, 0为第二组
        d[i].index_ = i; //作业序号
    }
    sort(d, d + num, cmp);

    int left = 0, right = num-1;
    for(int i = 0; i < num; ++i){
        if(d[i].group_)//如果是第一组 则从左往右放
        {
            c[left++] = d[i].index_;
        }else{
            c[right--] = d[i].index_;
        }
    }

    //计算最优调度序列下的消耗总时间
    int value1 = a[ c[0] ];
    int value2 = b[ c[0] ];
    for(int i = 1; i < num; ++i)
    {
        value1 += a[ c[i] ];
        value2 =  value2 > value1 ? value2 + b[ c[i] ] : value1 + b[ c[i] ];//求取消耗总时间的最大值
    }

    delete[]  d;
    return value2;
}
void Print()
{
    for(int i = 0; i < num; ++i){
        if(i) printf(" ");
        printf("%d",c[i]);
    }
    printf("\n");
}
int main()
{
    Init();
    Input();
    int ans = FlowShop(a,b,c);
    Print();//输出最优调度序列
    printf("The least time is : %d\n",ans);
    return 0;
}
/*
样例输入:
4
2 5 9 12
7 3 10 13
0 2 3 1
The least time is : 39
*/