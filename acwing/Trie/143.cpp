#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int maxn=1e5+10;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
int a[maxn];
int son[31*maxn][2], idx;
// M=31*maxn 代表一个数字串二进制可以有多长

inline void insert(int x)
{
    int p=0;  // 根节点
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;  // 取X的第i位的二进制数是什么  x>>k&1(前面的模板)
        if (!son[p][u]) son[p][u] = ++idx;  // 如果插入中发现没有该子节点,开出这条路
        p = son[p][u];  // 指针指向下一层
    }
}

inline int search(int x)
{
    int p=0, res=0;
    for (int i = 30; i >= 0; i--)
    { //                                从最大位开始找
        int u = x>>i&1;
        if (son[p][u])  // 如果当前层有对应的不相同的数
        {  // p指针就指到不同数的地址
            p = son[p][u];
            res = res*2+1;
            // *2相当左移一位  然后如果找到对应位上不同的数res+1 例如    001
        }  //                                                    010 
        else //                                                  011
        {
            p = son[p][u];
            res = res*2;
        }
    }
    return res;
}

int main()
{
    ios
    cin >> n;
    idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, search(a[i]));
    }
    cout << res << endl;
    return 0;
}