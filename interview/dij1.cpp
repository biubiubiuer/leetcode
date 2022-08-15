#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define fir first
#define sec second
#define ll long long
#define plii pair<ll, pii>

const int N = 1e2+10;

int a[N][N], b[N][N];
int vis[N][N];
ll d[N][N];
ll calc1(pii p, int tm){
    int mod = a[p.fir][p.sec] + b[p.fir][p.sec];
    int x = tm/mod;
    int y = tm%mod;
    if(y < a[p.fir][p.sec]) return tm;
    else return tm + (mod-y);
}
ll calc2(pii p, int tm){
    int mod = a[p.fir][p.sec] + b[p.fir][p.sec];
    int x = tm/mod;
    int y = tm%mod;
    if(y >= a[p.fir][p.sec]) return tm;
    else return tm + (a[p.fir][p.sec]-y);
}
priority_queue<plii> q;
int dx[4]{-1,1,0,0};
int dy[4]{0,0,-1,1};
int n, m;
int valid(pii p){
    return p.fir>=1 && p.fir<=n && p.sec>=1 && p.sec<=m;
}
ll dijkstra(pii s,pii t){
    memset(vis,0, sizeof(vis));
    memset(d,0x3f, sizeof(d));
    d[s.fir][s.sec] = 0;
    q.push(plii{0, s});
    while(!q.empty()){
        pii x = q.top().sec; q.pop();
        if(x == t){
            return d[x.fir][x.sec];
        }
        for(int i=0; i<2; i++){
            pii y = pii{x.fir+dx[i], x.sec+dy[i]};
            if(!valid(y)) continue;
            ll nt = calc1(x, d[x.fir][x.sec])+1;
            if(nt < d[y.fir][y.sec]){
                d[y.fir][y.sec] = nt;
                q.push(plii{-nt,y});
            }
        }
        for(int i=2; i<4; i++){
            pii y = pii{x.fir+dx[i], x.sec+dy[i]};
            if(!valid(y)) continue;
            ll nt = calc2(x, d[x.fir][x.sec])+1;
            if(nt < d[y.fir][y.sec]){
                d[y.fir][y.sec] = nt;
                q.push(plii{-nt,y});
            }
        }
    }
    return d[t.fir][t.sec];
}
int main(){
    pii s, t;
    scanf("%d%d %d%d %d%d",&n,&m,&s.fir,&s.sec,&t.fir,&t.sec);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("%lld\n",dijkstra(s,t));
    return 0;
}
