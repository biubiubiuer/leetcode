#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int N = 1005;

char s[N];

// 暴力 双指针 n2
inline string longestPalindrome(string s) {
    int res = 0;
    string str;
    for (int i = 0; i < s.size(); i ++ ) {
        for (int j = 0; i - j >= 0 && i + j < s.size(); j ++ ) {
            if (s[i - j] == s[i + j]) {
                if ((j << 1) + 1 > res) {
                    res = (j << 1) + 1;
                    str = s.substr(i - j, (j << 1) + 1);
                }
            }
            else break;
        }

        for (int j = i, k = i + 1; j >= 0 && k < s.size(); j -- , k ++ ) {
            if (s[j] == s[k]) {
                if (k - j + 1 > res) {
                    res = k - j + 1;
                    str = s.substr(j, k - j + 1);
                }
            }
            else break;
        }
    }

    return str;
}

// 动态规划
// dp[i][j]: 下标从 i 到 j 的子串是不是回文串, true -> 1, false -> 0
inline string longestPalindrome1(string s) {
    int len = s.size();
    if (len == 0 || len == 1) return s;

    int start = 0;  // 回文串起始位置
    int max = 1;  // 回文串最大长度
    vector<vector<int>> dp(len, vector<int>(len));
    
    /*
    base case:
    dp[i][i] = 1;  // 单个字符是回文串
    dp[i][i + 1] = 1 if s[i] == s[i + 1];  // 连续两个相同字符是回文串
    */

    // set base case
    for (int i = 0; i < len; i ++ ) {
        dp[i][i] = 1;
        if (i < len - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            max = 2;
            start = i;
        }
    }
    
    // l 表示检索的子串长度, 等于 3 表示先检索长度为 3 的子串
    for (int l = 3; l <= len; l ++ ) {
        for (int i = 0; i + l - 1 < len; i ++ ) {
            int j = l + i - 1;  // 终止字符位置

            // 状态转移
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                start = i;
                max = l;
            }
        }
    }

    return s.substr(start, max);
}

inline int expendaroundcenter(string s, int l, int r) {
    // 计算以 left 和 right 为中心的回文串长度
    while (l >= 0 && r < s.size() && s[r] == s[l]) {
        l --, r ++ ;
    }
    return r - l - 1;
}

// 中心扩展法
inline string longestPalindrome2(string s) {
    int len = s.size();
    if (len == 0 || len == 1) return s;

    int start = 0;  // 记录回文子串的起始位置
    int end = 0;  // 记录回文子串的终止位置
    int mlen = 0;  // 记录最大回文子串的长度

    for (int i = 0; i < len; i ++ ) {
        int len1 = expendaroundcenter(s, i, i);  // 一个元素为中心
        int len2 = expendaroundcenter(s, i, i + 1);  // 两个元素为中心

        mlen = max(max(len1, len2), mlen);
        if (mlen > end - start + 1) {
            start = i - ((mlen - 1) >> 1);
            end = i + (mlen >> 1);
        }
    }

    return s.substr(start, mlen);
}

int main(){

    for (int i = 0; i < N; i ++ ) {
        char c = getchar();
        if (c == '#') break;
        s[i] = c;
    }
  
    string res = longestPalindrome1(s);

    cout << res << endl;

    return 0;
}
