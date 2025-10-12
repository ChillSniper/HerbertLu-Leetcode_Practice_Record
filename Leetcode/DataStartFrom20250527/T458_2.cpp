#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class UnionSerach{
public:
    UnionSerach(int n): Rank(n, 0), Father(n){
        UnionCnt = n;
        for(int i = 0;i < n;i ++){
            Father[i] = i;
        }
    }
    int FindFather(int x){
        if(Father[x] == x){
            return x;
        }
        int fx = FindFather(Father[x]);
        Father[x] = fx;
        return fx;
    }
    void Union(int x, int y){
        int fx = FindFather(x);
        int fy = FindFather(y);
        if(fx == fy){
            return ;
        }
        -- UnionCnt;
        if(Rank[fx] > Rank[fy]){
            Father[fy] = fx;
        }
        else{
            if(Rank[fx] == Rank[fy]){
                Rank[fy] ++;
            }
            Father[fx] = fy;
        }
    }
    int UnionCnt;
private:
    vector<int> Rank, Father;
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // 这个题什么意思呢，先对边进行排序。小的边加进去，大的边：
        // 如果加入边，会减少连通分量，但是会增大最大成本。
        // 一开始的时候连通分量是大于k的，要不断地加入边以减少连通分量。
        UnionSerach example(n);
        sort(edges.begin(), edges.end(), [](auto& x, auto& y){
            return x[2] < y[2];
        });
        if(k == n){
            return 0;
        }
        for(auto& item : edges){
            int u = item[0], v = item[1], w = item[2];
            example.Union(u, v);
            if(example.UnionCnt <= k){
                return w;
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}