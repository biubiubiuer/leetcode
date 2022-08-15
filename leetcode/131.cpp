// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #define ios                      \
//     ios::sync_with_stdio(false); \
//     cin.tie(nullptr);            \
//     cout.tie(nullptr);
// using namespace std;

// vector<vector<string>> res;
// vector<string> ares;
// string spath;
// int T;

// inline bool is_huiwen(string s)
// {
//     int n = s.size();
//     if (n == 0)
//     {
//         cout << "size if string substr is empty" << endl;
//         return false;
//     }
//     int mid = n >> 1;
//     for (int i = 0; i < mid; i++)
//         if (s[i] != s[n - 1 - i])
//             return false;
//     return true;
// }

// inline bool add_char(string s, char c)
// {
//     s += c;
//     if (is_huiwen(s))
//         return true;
//     else
//         return false;
// }

// void dfs(string s, int begin)
// {
//     if (begin == s.size())
//     {
//         res.push_back(ares);
//         ares.clear();
//         return;
//     }

//     for (int i = begin; i < s.size(); i++)
//     {
//         // 字符加进上一个字符串
//         if (add_char(spath, s[i]))
//         {
//             spath += s[i];
//             dfs(s, begin + 1);
//             cout << "before pop: " << spath << endl;
//             spath.pop_back();
//             cout << "after pop: " << spath << endl;
//         }
//         else
//         {
//             ares.push_back(spath);
//             spath.clear();
//         }

//         // 开一个新字符串
//         ares.push_back(spath);
//         spath.clear();
//         dfs(s, begin + 1);
//     }
// }

// vector<vector<string>> partition(string s)
// {
//     dfs(s, 0);
//     return res;
// }

// int main()
// {
//     vector<vector<vector<string>>> ans;
//     cin >> T;
//     while (T--)
//     {
//         string s;
//         cin >> s;
//         vector<vector<string>> myres;
//         myres = partition(s);
//         ans.push_back(myres);
//         res.clear();
//         ares.clear();
//         spath.clear();
//     }
    
//     for (int k = 0; k < ans.size(); k++)
//     {
//         for (int i = 0; i < ans[k].size(); i++)
//         {
//             for (int j = 0; j < ans[k][j].size(); j++)
//                 cout << ans[k][i][j] << endl;
//             cout << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }




#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
const int N = 100010;

vector<vector<string>> res;
vector<string> ares;
// string spath;
bool dp[N][N];
int T;

void dfs(string s, int begin)
{
    if (begin == s.size())
    {
        res.push_back(ares);
        return;
    }

    for (int i = begin; i < s.size(); i++)
    {
        if (dp[begin][i])
        {
            ares.push_back(s.substr(begin, i+1));
            dfs(s, i+1);
            ares.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    if (s.size() == 0) return res;

    // 预处理
    // 状态：dp[i][j] 表示 s[i][j] 是否是回文
    // 状态转移方程：在 s[i] == s[j] 的时候，dp[i][j] 参考 dp[i + 1][j - 1]
    for (int r = 0; r < s.size(); r++)
        // 注意：left <= right 取等号表示 1 个字符的时候也需要判断
        for (int l = 0; l <= r; l++)
            if (s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1]) )
                dp[l][r] = true;

    dfs(s, 0);
    return res;
}

int main()
{
    vector<vector<vector<string>>> ans;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        res = partition(s);
        ans.push_back(res);
        res.clear();
        ares.clear();
        memset(dp, false, sizeof dp);
        // spath.clear();
    }
    
    for (int k = 0; k < ans.size(); k++)
    {
        for (int i = 0; i < ans[k].size(); i++)
        {
            for (int j = 0; j < ans[k][j].size(); j++)
                cout << ans[k][i][j] << endl;
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}