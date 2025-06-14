#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Father = vector<int>(n + 1, 0);
        Rank = Father;
        Init(n);
        for(int i = 0;i < n;i ++){
            if(Judge(edges[i][0], edges[i][1])) return {edges[i][0], edges[i][1]};
            Union(edges[i][0], edges[i][1]);
        }
        return {};
    }
private:
    vector<int> Father, Rank;
    void Init(int n){
        for(int i = 1;i <= n;i ++) Father[i] = i;
    }
    int FindFather(int x){
        if(Father[x] == x) return x;
        Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        if(fx == fy) return ;
        if(Rank[fx] > Rank[fy]){
            Father[fy] = fx;
        } else{
            if(Rank[fx] == Rank[fy]){
                Rank[fy] ++;
            }
            Father[fx] = fy;
        }
    }
    bool Judge(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        return fx == fy;
    }
};