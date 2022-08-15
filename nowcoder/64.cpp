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
#include<unordered_map>
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

class MagicDictionary 
{
    unordered_map<int, vector<string>> umap;
public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary)
    {
        for (auto& str : dictionary)
            umap[str.size()].push_back(str);
    }

    bool search(string searchWord)
    {
        int n = searchWord.size();
        vector<string> strs = umap[n];
        for (string & str : strs)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++) 
            {
                if (str[i] != searchWord[i]) ++ cnt;
                if (cnt > 1) break;
                if (i == n - 1 && cnt == 1) return true;
            }
        }
        return false;
    }
};

struct Trie
{
    bool isEnd;
    vector<Trie*> children;
    Trie() : isEnd(false), children(26, nullptr) {}
    ~Trie()
    {
        for (Trie* t : children)
            if (t) delete t;
    }
};

class MagicDictionary2
{
    Trie* root;
    void addWord(string& str)
    {
        Trie* cur = root;
        for (char& c : str)
        {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool dfs(Trie* cur, string& word, int idx, int cnt)
    {
        if (idx == word.size())
            if (cnt == 1 && cur->isEnd) return true;
            else return false;
        
        for (int i = 0; i < 26; i ++ ) 
        {
            // 不进入空节点
            if (cur->children[i] == nullptr) continue;
            if ('a' + i == word[idx])
                if (dfs(cur->children[i], word, idx + 1, cnt)) return true;
            else if (cnt == 0 && 'a' + i != word[idx])
                if (dfs(cur->children[i], word, idx + 1, cnt + 1)) return true;
        }
        return false;
    }
public:
    MagicDictionary2() 
    {
        root = new Trie();
    }
        
    void buildDict(vector<string> dictionary)
    {
        for (string& str : dictionary)
            addWord(str);
    }

    bool search(string searchWord)
    {
        Trie* cur = root;
        return dfs(cur, searchWord, 0, 0);
    }
    
};

int main()
{
    ios
    vector<string> dictionary;
    int n;
    scanf("%d", &n);
    while (n--) 
    {
        string s;
        scanf("%s", &s);
        dictionary.push_back(s);
    }

    MagicDictionary* magicDictionary = new MagicDictionary();
    magicDictionary->buildDict(dictionary);

    vector<string> inputs;
    int m;
    scanf("%d", &m);
    while (m--)
    {
        string s;
        scanf("%s", &s);
        inputs.push_back(s);
    }

    vector<bool> res;
    for (auto t : inputs) 
    {
        res.push_back(magicDictionary->search(t));
    }

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}