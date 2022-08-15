#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

const double PI=acos(-1.0);
const double eps=1e-6;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e5+10;
const int maxm=100+10;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int T,n,m;

vector<vector<int> > res;
vector<int> path;
int add;
//int times;

inline void dfs(vector<int>& nums, int target)
{
    if (add == target) {
        res.push_back(path);
        return;
    }
    if (add > target) {
        return;
    }

    for (int i = 0; i < nums.size(); i ++ ) {
        path.push_back(nums[i]);
        add += nums[i];
        //cout << ++times << endl;
        dfs(nums, target);
        add -= nums[i];
        path.pop_back();
    }
}

inline vector<vector<int>> del_dup(vector<vector<int>>& li) {
    int sz = li.size();
    for (int i = 0; i < sz; i++)
    {
        sort(li[i].begin(), li[i].end());
        if (i)
        {
            
            for (int k = i-1; k >= 0; k--) 
            {
                bool t = true;
                int j;
                int mn = min(li[i].size(), li[k].size()), mx =max(li[i].size(), li[k].size()); 
                for (j = 0; j < mn; j++ ) 
                {
                    if (li[i][j] != li[k][j])
                    {
                        t = false;
                        break;
                    }
                }
                if (t && mn == mx)
                {
                    li.erase(li.begin()+i);
                    i--;
                    sz--;
                }
            }
            
        }
    }
    return res;
}

inline void combinationSum(vector<int>& candidates, int target)
{
    dfs(candidates, target);
    del_dup(res);
}

int main()
{
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        for (int & i : a) cin >> i;
        combinationSum(a, m);
        for (int i = 0; i < res.size(); i ++ )
        {
            for (int j = 0; j < res[i].size(); j ++ )
                cout << res[i][j] << ' ';
            cout << endl;
        }
        cout << "--------------res.size(): " << res.size() << endl;
        res.clear();
        path.clear();
        add = 0;
    }
    return 0;

}