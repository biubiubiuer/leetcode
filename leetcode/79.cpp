// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cstring>
// #define ios                      \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);

// using namespace std;

// string path;
// int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
// bool used[7][7];
// int T;

// inline bool is_idx(int x, int y, int n, int m)
// {
//     bool res = x >= 0 && x < n && y >= 0 && y < m;
//     if (res)
//         cout << 'T' << endl;
//     else
//         cout << 'F' << endl;
// }

// bool dfs(vector<vector<char>> &board, int n, int m, int x, int y, string &word, int begin, int size)
// {
//     if (begin == size)
//     {
//         return true;
//     }

//     used[x][y] = true;
//     path += word[begin];
//     cout << "path: " << path << endl;

//     for (int k = 0; k < 4; k++)
//     {
//         cout << "word[begin]: " << word[begin] << endl;
//         cout << "begin: " << begin << endl;
//         cout << "x: " << x << ", y: " << y << endl;

//         /*
//         TODO: 出错原因: 还没进入下一层递归, path就已经满足了
//         */

//         if (is_idx(x + dx[k], y + dy[k], n, m) && board[x + dx[k]][y + dy[k]] == word[begin + 1] && !used[x + dx[k]][y + dy[k]])
//         {
//             // cout << "before_dfs_of_dfs" << endl;
//             dfs(board, n, m, x + dx[k], y + dy[k], word, begin + 1, size);
//         }
//     }

//     used[x][y] = false;
//     path.pop_back();

//     return false;
// }

// bool exist(vector<vector<char>> &board, string word)
// {
//     if (word == "")
//         return false;
//     char c = word[0];
//     cout << "c: " << c << endl;
//     int n = board.size(), m = board[0].size();
//     bool res = false;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             if (board[i][j] == c)
//             {
//                 cout << "before_dfs" << endl;
//                 res = dfs(board, board.size(), board[0].size(), i, j, word, 0, word.size());
//                 if (res)
//                     return true;
//             }

//     return false;
// }

// int main()
// {
//     scanf("%d", &T);
//     while (T--)
//     {
//         string word;
//         cin >> word;
//         int n, m;
//         scanf("%d%d", &n, &m);
//         vector<vector<char>> board(n, vector<char>(m));
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 cin >> board[i][j];

//         bool res = exist(board, word);
//         if (res)
//             cout << "true" << endl;
//         else
//             cout << "false" << endl;
//         path.clear();
//         memset(used, false, sizeof used);
//     }
//     return 0;
// }

#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int T;

bool dfs(vector<vector<char>> &board, string &word, int u, int x, int y)
{
    if (board[x][y] != word[u])
        return false;
    if (u == word.size() - 1)
        return true;
    char t = board[x][y];
    board[x][y] = '.';
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < board.size() && b >= 0 && b < board[a].size())
        {
            if (dfs(board, word, u + 1, a, b))
                return true;
        }
    }
    board[x][y] = t;
    return false;
}

bool exist(vector<vector<char>> &board, string str)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            if (dfs(board, str, 0, i, j))
                return true;
    return false;
}

int main()
{
    cin >> T;
    vector<string> ans;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        bool res = exist(board, word);
        if (res)
            ans.push_back("true");
        else
            ans.push_back("false");
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}