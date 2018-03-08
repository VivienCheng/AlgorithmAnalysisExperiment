#include<iostream>
#include<queue>
using namespace std;

int n,x,y,sum;
void See(priority_queue<int, vector<int>, greater<int> > p)
{
    bool first = true;
    while(!p.empty())
    {
        if(first) {first = false;}
        else printf(" ");
        printf("%d",p.top());
        p.pop();
    }
    printf("\n");
}
int main()
{
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> > p;
    sum = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&x);
        p.push(x);
    }
    printf("The process is:\n");
    See(p);
    while(p.size() > 1)
    {
        x = p.top(); p.pop();
        y = p.top(); p.pop();
        sum += x + y;
        p.push(x+y);
        See(p);
    }
    sum += p.top();p.pop();
    printf("The result is: %d\n",sum);
}
/*
样例输入:
7
7 6 5 4 3 2 1
The process is:
1 2 3 4 5 6 7
3 3 4 5 6 7
4 5 6 6 7
6 6 7 9
7 9 12
12 16
28

样例输出：
102
*/