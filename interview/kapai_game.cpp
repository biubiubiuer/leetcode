// #include <cstdio>
// using namespace std;

// // const int N = 100010;
// const int N = 15;
// int a[N], n;
// int b[N][N];

// int main()
// {
//     scanf("%d", &n);
//     for (int ii = 1; ii <= n; ii ++ ) scanf("%d", &a[ii]);

//     int i = 0, j = 0;
//     b[n][n] = a[n], b[n-1][n-1] = a[n-1], b[n-1][n] = a[n];
//     for (i = n-2; i >= 1; i -- ) 
//     {
//         int x = b[i+1][n-1], y = b[i+1][n];
//         b[i][i] = x, b[i][i+1] = y;
//         b[i][i+2] = a[i];
//         if (i < n - 2) {
//             for (j = n; j >= i + 3; j -- )
//             {
//                 b[i][j] = b[i+1][j-2];
//             }
//         }
//     }

//     for (int k = 1; k <= n; k ++ )
//     {
//         printf("%d ", b[1][k]);
//     }
//     printf("\n");
//     return 0;
// }



#include <cstdio>
using namespace std;

const int N = 100010;
int a[N], n;
int b[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    if (n <= 2)
    {
        for (int i = 1; i <= n; i ++ ) printf("%d ", a[i]);
        printf("\n");
        return 0;
    }

    if (n == 3)
    {
        printf("%d %d %d \n", a[2], a[3], a[1]);
        return 0;
    }

    int i = 0, j = 0;
    b[n][n] = a[n], b[n-1][n-1] = a[n-1], b[n-1][n] = a[n];
    for (i = n-2; i >= 1; i -- )
    {
        int x = b[i+1][n-1], y = b[i+1][n];
        b[i][i] = x, b[i][i+1] = y;
        b[i][i+2] = a[i];
        if (i < n - 2)
        {
            for (j = n; j >= i + 3; j -- )
            {
                b[i][j] = b[i+1][j-2];
            }
        }
    }

    for (int k = 1; k <= n; k ++ )
    {
        printf("%d ", b[1][k]);
    }
    printf("\n");
    return 0;
}