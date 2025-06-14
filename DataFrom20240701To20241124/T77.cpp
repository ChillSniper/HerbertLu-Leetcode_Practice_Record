#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // 递归的问题在于如何选取出数并且将其标记
        DFS(n, 1, k);
        return result;
    }
private:
    void DFS(int n, int st, int k){
        if(k == 0){
            result.push_back(tmp);
            return ;
        }
        if(st > n - k + 1) return ;
        for(int i = st;i <= n - k + 1;i ++){ // 可以在此处剪枝优化 将i的最大值进行优化
            tmp.push_back(i);
            DFS(n, i + 1, k - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> result;
    vector<int> tmp;
};

int main(){

    return 0;
}