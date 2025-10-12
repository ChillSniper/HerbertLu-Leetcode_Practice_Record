#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // �ݹ�������������ѡȡ�������ҽ�����
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
        for(int i = st;i <= n - k + 1;i ++){ // �����ڴ˴���֦�Ż� ��i�����ֵ�����Ż�
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