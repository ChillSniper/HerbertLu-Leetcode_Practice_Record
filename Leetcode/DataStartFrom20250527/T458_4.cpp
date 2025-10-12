#include <bits/stdc++.h>
using namespace std;
#define Test

const int N = 20, M = N * N * 2;
int Head[N], To[N * N], Nxt[M], idx;

class Solution {
public:
int maxLen(int n, vector<vector<int>>& edges, string label) {
    for(auto item : label){
        cnt[item] ++;
    }
    idx = 0;
    _n = n;
    MaxLen = 1;
    _label = label;
    memset(Head, -1, sizeof Head);
    memset(To, 0, sizeof To);
    for(auto& item : edges){
        int u = item[0], v = item[1];
        AddEdge(u, v);
        AddEdge(v, u);
    }
    vector<int> vis(n, 0);
    for(int i = 0;i < n;i ++){
        char ch = label[i];
        if(cnt[ch] == 1){
            continue;
        }
        for(int j = 0;j < n;j ++){
            vis[j] = 0;
        }
        string cur;
        cur += label[i];
        Dfs(i, cur, vis);
    }
    return MaxLen;
}
private:
    int _n, MaxLen;
    string _label;
    unordered_map<char, int> cnt;
    bool Judge(string s){
        int sz = s.size();
        for(int i = 0, j = sz - 1;i < j;i ++, j --){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    void Dfs(int u, string cur, vector<int>& vis){
        bool Flag = Judge(cur);
        if(Flag){
            MaxLen = max(MaxLen, (int)cur.size());
        }
        vis[u] = 1;
        for(int i = Head[u];i != -1;i = Nxt[i]){
            int v = To[i];
            if(!vis[v]){
                string tmp = cur + _label[v];
                Dfs(v, tmp, vis);
                vis[v] = 0;
            }
        }
    }
    void AddEdge(int u, int v){
        To[idx] = v;
        Nxt[idx] = Head[u];
        Head[u] = idx ++;
    }
};

int main(){
    return 0;
}