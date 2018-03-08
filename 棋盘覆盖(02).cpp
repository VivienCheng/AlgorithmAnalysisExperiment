#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 8;

int tile = 0,size = 8;
int Board[maxn][maxn];

void See()
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j){
            if(j) printf(" ");
            printf("%2d",Board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size == 1) return;
    int t = tile++;
    int s = size / 2;

    if(dr < tr + s && dc < tc + s)
        ChessBoard(tr,tc,dr,dc,s);
    else{
        Board[tr+s-1][tc+s-1] = t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    if(dr < tr + s && dc >= tc + s)
        ChessBoard(tr,tc+s,dr,dc,s);
    else{
        Board[tr+s-1][tc+s] = t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }

    if(dr >= tr + s && dc < tc + s)
        ChessBoard(tr+s,tc,dr,dc,s);
    else{
        Board[tr+s][tc+s-1] = t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    if(dr >= tr + s && dc >= tc + s)
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else{
        Board[tr+s][tc+s] = t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{
    memset(Board,0,sizeof Board);
    ChessBoard(0,0,0,1,size);
    See();
    return 0;
}
/*
样例输出:
2  0  3  3  7  7  8  8
2  2  1  3  7  6  6  8
4  1  1  5  9  9  6 10
4  4  5  5  0  9 10 10
12 12 13  0  0 17 18 18
12 11 13 13 17 17 16 18
14 11 11 15 19 16 16 20
14 14 15 15 19 19 20 20
*/