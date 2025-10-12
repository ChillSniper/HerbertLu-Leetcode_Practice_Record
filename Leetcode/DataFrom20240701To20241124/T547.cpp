#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
//#define SearchCollectionWay
//#define DFSWay
#define BFSWay
using namespace std;

#ifdef BFSWay
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int> visited(n);
        deque<int> dq;
        int cnt = 0;
        for(int i = 0;i < n;i ++){
            if(!visited[i]){
                dq.push_back(i); 
                visited[i] = 1;
                cnt ++;
            }
            while (!dq.empty())
            {
                int m = dq.front(); dq.pop_front();
                for(int j = 0;j < n;j ++){
                    if(!visited[j] && isConnected[m][j]){
                        dq.push_back(j);
                        visited[j] = 1;
                    }
                }
            }
        }
        return cnt;
    }
};
#endif

#ifdef DFSWay
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int> visited(n);
        int cnt = 0;
        for(int i = 0;i < n;i ++){
            if(!visited[i]){
                visited[i] = 1;
                DFS(isConnected, visited, n, i);
                cnt ++;
            }
        }
        return cnt;
    }
    void DFS(vector<vector<int>>& isConnected, vector<int>& visited, int n, int i){
        for(int j = 0;j < n;j ++){
            if(isConnected[i][j] && !visited[j]){
                visited[j] = 1;
                DFS(isConnected, visited, n, j);
            }
        }
    }
};
#endif

#ifdef SearchCollectionWay
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        for(int i = 1;i <= n;i ++) MakeSet(i);
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(isConnected[i][j]) Union(i + 1, j + 1);
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++){
            if(Father[i] <= 0) ans ++;
        }
        return ans;
    }
    void MakeSet(int x){
        Father[x] = 0;
    }
    int FindFather(int x){
        if(Father[x] <= 0) return x;
        Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        if(fx == fy) return;
        if(Father[fx] > Father[fy]){ // fy is root
            Father[fx] = fy;
        } else{
            if(Father[fx] == Father[fy]) Father[fx] --;
            Father[fy] = fx;
        }
    }
private:
    int Father[210] = {0};
};
#endif

int main(){
    return 0;
}