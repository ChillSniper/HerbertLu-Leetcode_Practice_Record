#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

const int N = 1e2 + 10;
const int INF = 0x3f3f3f3f;
int Head[N], vis[N], idx;
struct Edge
{
    int to, Nxt;
};
Edge e[N * N * 2];
class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        memset(Head, -1, sizeof Head);
        int sz_pro = properties.size();
        for(int i = 0;i < sz_pro;i ++){
            for(int j = 0;j < sz_pro;j ++){
                if(j == i || intersect(properties[i], properties[j]) < k)
                    continue;
                AddEdge(i, j);
            }
        }
        int ans = 0;
        for(int i = 0;i < sz_pro;i ++){
            if(!vis[i]){
                ans ++;
                Dfs(i);
            }
        }
        return ans;
    }
private:
    void Dfs(int u){
        if(vis[u])
            return ;
        vis[u] = 1;
        for(int i = Head[u];i != -1;i = e[i].Nxt){
            int v = e[i].to;
            Dfs(v);
        }
    }
    int intersect(vector<int>& a, vector<int>& b){
        int cnt = 0, sz_a = a.size(), sz_b = b.size();
        unordered_set<int> st;
        unordered_set<int> store;
        for(int i = 0;i < sz_a;i ++)    
            st.insert(a[i]);
        for(int i = 0;i < sz_b;i ++)
            if(st.count(b[i]) && !store.count(b[i]))
                cnt ++, 
                store.insert(b[i]);
        
        return cnt;
    }
    void AddEdge(int u, int v){
        e[idx].Nxt = Head[u];
        e[idx].to = v;
        Head[u] = idx ++;
    }
};
#define Test
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<vector<int>> p = {{1, 1}, {1, 1}};
    int k = 2;
    Solution s;
    cout << s.numberOfComponents(p, k);
    return 0;
}