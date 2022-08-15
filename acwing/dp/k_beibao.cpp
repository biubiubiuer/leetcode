// #include<iostream>
// using namespace std;
// const int N = 17;
// int f[N][N];
// int v[N],w[N];
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1 ; i <= n ;i ++)
//     {
//         cin>>v[i]>>w[i];
//     }

//     for(int i = 1 ; i<=n ;i++)
//     for(int j = 1 ; j<=m ;j++)
//     {
//         for(int k = 0 ; k*v[i]<=j ; k++)
//             f[i][j] = max(f[i-1][j],f[i-1][j-k*v[i]]+k*w[i]);
//     }

//     cout<<f[n][m]<<endl;
// } // TLE


// #include<iostream>
// using namespace std;
// const int N = 1010;
// int f[N][N];
// int v[N],w[N];
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1 ; i <= n ;i ++)
//     {
//         cin>>v[i]>>w[i];
//     }

//     for(int i = 1 ; i <=n ;i++)
//     for(int j = 1 ; j <=m ;j++)
//     {
//         f[i][j] = f[i-1][j];
//         if(j-v[i]>=0)
//             f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
//     }
//     cout<<f[n][m]<<endl;
// } // [][]

#include<iostream>
using namespace std;
const int N = 1010;
int f[N];
int v[N],w[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = v[i] ; j<=m ;j++)
    {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;
}

