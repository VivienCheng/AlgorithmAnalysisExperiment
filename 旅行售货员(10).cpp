#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100 + 8;

int n;//顶点个数
int gra[maxn][maxn],x,y,z;
int p[maxn],bestP[maxn];//p:当前解  bestP:当前最优解
int curC,bestC;//curC:当前费用 bestC:当前最优值


void Backtrack(int cur)
{

    if(cur == n){
        int u = p[n-1], v = p[n];
        if(gra[u][v] && gra[v][1] && (bestC > curC + gra[u][v]  +  gra[v][1] || !bestC) ){
            for(int j = 1; j <= n; ++j) bestP[j] = p[j];
            bestC = curC + gra[u][v] + gra[v][1];
        }
    }else{
        int a = p[cur-1];
        for(int j = cur; j <= n; ++j){
            int b = p[j];
            if(gra[a][b] && (bestC > curC + gra[a][b] || !bestC)){
                swap(p[cur],p[j]);
                curC += gra[a][p[cur]];//当前费用累加
                Backtrack(cur + 1); // 排列向右扩展,排列树向下一层扩展
                curC -= gra[a][p[cur]];
                swap(p[cur],p[j]);
            }
        }
    }
}

int main()
{
    memset(gra,0,sizeof gra);
    memset(p,0,sizeof p);
    memset(bestP,0,sizeof bestP);
    bestC = 0;
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> gra[i][j];
        }
    }
    for(int i = 1; i <= n; ++i)  p[i] = i;
    Backtrack(2);

    cout << "最短回路为:" << endl;
    for(int i = 1; i <= n; ++i){
        if(i != 1) cout << "--->";
        cout << bestP[i];
    }
    cout << "-->1" << endl;
    cout << "最短回路的长度为: " << bestC << endl;
}
/*
样例输入：
4
0 30 6 4
30 0 5 10
6 5 0 20
4 10 20 0

样例输出：
最短回路为:
1--->3--->2--->4-->1
最短回路的长度为: 25
*/