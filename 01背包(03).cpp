#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1000 + 8;

int dp[maxn], weight[maxn], value[maxn];
int num,maxWeight;

void Init()
{
    memset(weight,0,sizeof weight);
    memset(value,0,sizeof value);
}
void Input()
{
    scanf("%d %d",&num, &maxWeight);
    for(int i = 0; i < num; ++i)
    {
        scanf("%d",&weight[i]);
    }
    for(int i = 0; i < num; ++i)
    {
        scanf("%d",&value[i]);
    }
}
void See()
{
    for(int i = 0; i <= maxWeight; ++i){
        if(i) printf(" ");
        printf("%2d",dp[i]);
    }
    printf("\n");
}
void Solve()
{
    See();
    for(int i = 0; i < num; ++i) {
        for (int j = maxWeight; j >= weight[i]; --j) {
            dp[j] = max(dp[j],dp[j-weight[i]] + value[i]);
        }
        See();
    }
}
int main()
{
    Init();
    Input();
    printf("The process : \n");
    Solve();
    printf("The result : \n");
    printf("%d\n",dp[maxWeight]);
    return 0;
}
/*
样例输入:
5 10
1 2 3 4 5
5 4 3 2 1

样例输出:
The process :
0  0  0  0  0  0  0  0  0  0  0
0  5  5  5  5  5  5  5  5  5  5
0  5  5  9  9  9  9  9  9  9  9
0  5  5  9  9  9 12 12 12 12 12
0  5  5  9  9  9 12 12 12 12 14
0  5  5  9  9  9 12 12 12 12 14
The result :
14
*/

