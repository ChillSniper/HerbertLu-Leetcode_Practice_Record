#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m, Indegree[N];
unordered_map<int, vector<int>> mp;
int main(){
    // 这边有个很扯的点，由于数据量过大，不如使用一个map来记录有向边
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i ++){
        int s, t;
        scanf("%d%d", &s, &t);
        mp[s].push_back(t);
        Indegree[t] ++;
    }
    deque<int> dq;
    for(int i = 0;i < n;i ++){
        if(!Indegree[i]) dq.push_back(i);
    }
    vector<int> ans;
    while (!dq.empty())
    {
        int p = dq.front(); dq.pop_front();
        ans.push_back(p);
        for(int i = 0;i < mp[p].size();i ++){
            if(--Indegree[mp[p][i]] == 0){
                dq.push_back(mp[p][i]);
            }
        }
    }
    if(ans.size() == n){
        printf("%d", ans[0]);
        for(int i = 1;i < n;i ++)
            printf(" %d", ans[i]);
    } else printf("-1");
    return 0;
}