#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1000 + 8;
int n,k,x,ans,dist;
int a[maxn];

int main()
{
    scanf("%d%d",&n,&k);
    fill(a, a + maxn, 0);

    bool mark = false;
    for(int i = 0; i <= k; ++i)
    {
        scanf("%d",&a[i]);
        if(a[i] > n) {mark = true;}
    }

    printf("The result:\n");
    if(mark) {
        printf("No solution\n");
        return 0;
    }
    int curOil = n;
    for(int i = 0; i <= k; ++i)
    {
        if(a[i] > curOil)
        {
            curOil = n; //油箱最大的容积是n
            ans++;
        }
        curOil -= a[i];
    }
    if(ans < 0) printf("No Solution\n");
    else printf("%d\n",ans);
    return 0;
}
/*
7 7
1 2 3 4 5 1 6 6
The result:
4
*/