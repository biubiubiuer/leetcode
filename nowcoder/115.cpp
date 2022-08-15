#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                  \
    cout.tie(nullptr);

using namespace std;

const int N = 10010, M = N;
int idx;
int he[N], e[N], ne[N], in[N];
int T;

inline void reset()
{
    idx = 0;
    memset(he, 0, sizeof(he));
    memset(e, 0, sizeof(e));
    memset(ne, 0, sizeof(ne));
    memset(in, 0, sizeof(in));
}

inline void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = he[a];
    he[a] = idx++;
    in[b]++;
}

inline bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &ss)
{
    int n = nums.size();
    memset(he, -1, sizeof he);
    for (auto s : ss)
        for (int i = 1; i < s.size(); i++)
            add(s[i - 1], s[i]);

    deque<int> d;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            d.emplace_back(i);

    int loc = 0;
    while (!d.empty())
    {
        if (d.size() != 1)
            return false;
        auto t = d.front();
        d.pop_front();
        if (nums[loc++] != t)
            return false;
        for (int i = he[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--in[j] == 0)
                d.emplace_back(j);
        }
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    vector<string> ans;
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> nums(n);
        vector<vector<int>> ss(m, vector<int>(2));

        for (int i : nums)
            cin >> i;
        for (auto i : ss)
            cin >> i[0] >> i[1];

        bool res = sequenceReconstruction(nums, ss);
        if (res)
            ans.push_back("true");
        else
            ans.push_back("false");
        reset();
    }
    for (auto s : ans)
        cout << s << endl;
    return 0;
}