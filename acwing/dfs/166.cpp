// #include <iostream>
// #include <stdio.h>
// #include <string>
// #include <cstring>
// using namespace std;
// #define fir(i, a, b) for (int i = a; i <= b; i++)
// char str[10][10];
// int r[9], c[9], g[9], cnt[512], num[512], tot;
// inline int gc(int x, int y) //将二维数组变成一维数组
// {
//     return ((x / 3) * 3) + (y / 3);
// }
// inline void pd(int x, int y, int z) //位运算,修改当前位数z,第z位1变为0,0变为1.
// {
//     r[x] ^= 1 << z;        //横坐标
//     c[y] ^= 1 << z;        //纵坐标
//     g[gc(x, y)] ^= 1 << z; //九宫格
// }
// inline int lowbit(int x) //得到当前可以选择的合法数值.
// {
//     return x & (-x);
// }
// inline bool dfs(int now)
// {
//     if (now == 0)
//         return 1;
//     int temp = 10, x, y;
//     fir(i, 0, 8)
//         fir(j, 0, 8)
//     {
//         if (str[i][j] != '.')
//             continue;
//         int val = r[i] & c[j] & g[gc(i, j)]; //判断这一位是否合法,1为合法,0为不合法
//         if (!val)
//             return 0;
//         if (cnt[val] < temp) //找到当前能填合法数字最小的位置
//         {
//             temp = cnt[val];
//             x = i, y = j;
//         }
//     }
//     int val = r[x] & c[y] & g[gc(x, y)];
//     for (; val; val -= lowbit(val))
//     {
//         int z = num[lowbit(val)];
//         str[x][y] = '1' + z;
//         pd(x, y, z);
//         if (dfs(now - 1)) //下一位
//             return 1;
//         pd(x, y, z); //回溯
//         str[x][y] = '.';
//     }
//     return 0;
// }
// int main()
// {
//     //  freopen("stdin.in","r",stdin);
//     for (int i = 0; i < 1 << 9; i++)
//         for (int j = i; j; j -= lowbit(j))
//             cnt[i]++;
//     fir(i, 0, 8)
//         num[1 << i] = i;
//     char s[100];
//     while (~scanf("%s", s) && s[0] != 'e')
//     {
//         fir(i, 0, 8)
//             fir(j, 0, 8)
//                 str[i][j] = s[i * 9 + j];
//         fir(i, 0, 8)
//             r[i] = c[i] = g[i] = (1 << 9) - 1; //初始的是否都是合法的
//         tot = 0;
//         fir(i, 0, 8)
//             fir(j, 0, 8) if (str[i][j] != '.')
//                 pd(i, j, str[i][j] - '1'); //这一位已经选择
//         else tot++;                        //统计需要修改的个数
//                                            //      cout<<tot<<endl;
//         dfs(tot);
//         fir(i, 0, 8)
//             fir(j, 0, 8)
//                 s[i * 9 + j] = str[i][j]; //答案输出
//         puts(s);
//     }
//     return 0;
// }


// y总答案
#include <iostream>
#include <algorithm>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lowbit(x) (x&(-x))
const int N=9;

int ones[1<<N], mp[1<<N];//ones[]:一个二进制数有多少个1; map[]:lowbit()返回的二进制数最低位1在第几位
int row[N], col[N], cell[3][3];
char str[100];

inline void init()
{
    for(int i=0;i<N;i++) row[i]=col[i]=(1<<N)-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cell[i][j]=(1<<N)-1;
}
//求可选方案的交集
inline int get(int x,int y)
{
    return row[x]&col[y]&cell[x/3][y/3];
}
bool dfs(int cnt)
{
    if(!cnt) return true;
    //找出可选方案数最少的空格
    int minv=10;
    int x,y;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(str[9*i+j]=='.')
            {
                int t=ones[get(i,j)];
                if(t<minv)
                {
                    minv=t;
                    x=i,y=j;
                }
            }
    for(int i=get(x,y);i;i-=lowbit(i))
    {
        int t=mp[lowbit(i)];
        //修改状态
        row[x]-=1<<t;
        col[y]-=1<<t;
        cell[x/3][y/3]-=1<<t;
        str[9*x+y]='1'+t;
        if(dfs(cnt-1)) return true;
        //恢复现场
        row[x]+=1<<t;
        col[y]+=1<<t;
        cell[x/3][y/3]+=1<<t;
        str[9*x+y]='.';
    }
    return false;
}
int main()
{
    ios
    for(int i=0;i<N;i++) mp[1<<i]=i;
    for(int i=0;i<1<<N;i++) 
    {
        int s=0;
        for(int j=i;j;j-=lowbit(j)) s++;
        ones[i]=s;//i的二进制表示中有s个1
    }
    while(cin>>str,str[0]!='e')
    {
        init();
        int cnt=0;
        for(int i=0,k=0;i<N;i++)
            for(int j=0;j<N;j++,k++)
                if(str[k]!='.')
                {
                    int t=str[k]-'1';//把'1'~'9'下标改成0~8
                    row[i]-=1<<t;
                    col[j]-=1<<t;
                    cell[i/3][j/3]-=1<<t;
                }
                else cnt++;
        dfs(cnt);//把cnt个没有填过的格子填满
        cout<<str<<endl;
    }  
    return 0;
}