#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100 + 8;

bool gra[maxn][maxn];//bool类型 gra[i][j] true则代表i与j相连通(即相邻) false则代表i与不相连
int color[maxn];//有多少种可供选择的颜色
int nodenum,edgenum,colornum,sum,kase,x,y;

bool Judge(int a)
{
    for(int b = 1; b <= nodenum; ++b){
        if(gra[a][b] && color[a] == color[b]) return false;//如果a与b相邻,且a与a的颜色相同 那么就返回false
    }
    return true;
}
void Backtrack(int cur)
{
    if(cur > nodenum){
        sum++;
        for(int i = 1; i <= nodenum; ++i){
            if(i != 1) cout << " ";
            cout << color[i];
            if(i == nodenum) cout << endl;
        }
    }else{
        for(int i = 1; i <= colornum; ++i){
            color[cur] = i;
            if(Judge(cur)){ Backtrack(cur + 1); }
            color[cur] = 0;//回溯
        }
    }
}
int main()
{
    int cases = 0;
    cin >> kase;
    while(kase--) {
        printf("Case %d:\n",++cases);
        memset(gra, false, sizeof gra);
        memset(color, 0, sizeof color);
        sum = 0;
        cin >> nodenum >> edgenum >> colornum;
        for(int i = 1; i <= edgenum; ++i){
            cin >> x >> y;
            gra[x][y] = gra[y][x] = true;
        }
        Backtrack(1);
        printf("Total : %d\n", sum);
    }
}

/*
样例输入：
1
5 8 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5

样例输出：
1 2 3 4 1
1 2 3 4 3
1 2 4 3 1
1 2 4 3 4
1 3 2 4 1
1 3 2 4 2
1 3 4 2 1
1 3 4 2 4
1 4 2 3 1
1 4 2 3 2
1 4 3 2 1
1 4 3 2 3
2 1 3 4 2
2 1 3 4 3
2 1 4 3 2
2 1 4 3 4
2 3 1 4 1
2 3 1 4 2
2 3 4 1 2
2 3 4 1 4
2 4 1 3 1
2 4 1 3 2
2 4 3 1 2
2 4 3 1 3
3 1 2 4 2
3 1 2 4 3
3 1 4 2 3
3 1 4 2 4
3 2 1 4 1
3 2 1 4 3
3 2 4 1 3
3 2 4 1 4
3 4 1 2 1
3 4 1 2 3
3 4 2 1 2
3 4 2 1 3
4 1 2 3 2
4 1 2 3 4
4 1 3 2 3
4 1 3 2 4
4 2 1 3 1
4 2 1 3 4
4 2 3 1 3
4 2 3 1 4
4 3 1 2 1
4 3 1 2 4
4 3 2 1 2
4 3 2 1 4
Total : 48
*/