//非递归：
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
/*
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<typeinfo>
#include<time.h>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
#define inf 0x3f3f3f3f
#define PI 3.14
*/
const int maxn = 1e5 + 8;
int n,q,x,num;
int s[maxn];

bool binarySearch(int x)
{
    int left,right,mid;
    left = 0; right = n;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(s[mid] == x) return true;//如果s数组中间的元素与寻找元素值相等 返回真
        else if(s[mid] > x){//如果s数组中间的元素大于寻找元素值相等
            right = mid;//缩小范围 让范围右端下标变为mid
        }else if(s[mid] < x){//如果s数组中间的元素小于寻找元素值相等
            left = mid + 1;//缩小范围 让范围左端下标变为mid+1
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d", &s[i]);
    sort(s,s+n);//二分搜索之前需要先排序 使该数组有序 该过程时间复杂度为O(logn)
    scanf("%d",&q);
    num = 0;
    for(int i = 0; i < q; ++i) {
        scanf("%d", &x);
        if(binarySearch(x)) num++;//如果二分搜说能找到,就加一
    }
    printf("%d\n",num);//输出最后能在数组s中找到的元素
    return 0;
}

//**************************************************************************
//递归：
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 8;
int n,q,x,num;
int s[maxn];

bool BinarySearch(int left,int right,int x)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        if(s[mid] == x) return true;//如果s数组中间的元素与寻找元素值相等 返回真
        else if(s[mid] > x){//如果s数组中间的元素大于寻找元素值相等
            return BinarySearch(left,mid,x);//缩小范围 让范围右端下标变为mid
        }else if(s[mid] < x){//如果s数组中间的元素小于寻找元素值相等
            return BinarySearch(mid+1,right,x);//缩小范围 让范围左端下标变为mid+1
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d", &s[i]);
    sort(s,s+n);//二分搜索之前需要先排序 使该数组有序 该过程时间复杂度为O(logn)
    scanf("%d",&q);
    num = 0;
    for(int i = 0; i < q; ++i) {
        scanf("%d", &x);
        if(BinarySearch(0,n,x)) num++;//如果二分搜说能找到,就加一
    }
    printf("%d\n",num);//输出最后能在数组s中找到的元素
    return 0;
}
/*
输入样例:
5
1 2 3 4 5
3
3 4 1
输出结果:
3
*/