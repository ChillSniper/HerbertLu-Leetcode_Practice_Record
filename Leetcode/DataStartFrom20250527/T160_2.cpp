#include <bits/stdc++.h>
using namespace std;
#define Test
typedef long long ll;
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>> F(m, vector<ll>(n, 0));
        // �����ʲô��˼�أ����·��һ���㣬���Ҳ����յ㡣
        // ��ô��Ȼ��ż������벢֧���ȴ����ã���������ѡ����һ����Ȼ��ȥ���룬��֧��������á�
        for(int j = 1;j < n;j ++){
            F[0][j] = F[0][j - 1] + (waitCost[0][j] + (0 + 1) * (j + 1));
        }
        for(int i = 1;i < m;i ++){
            F[i][0] = F[i - 1][0] + (waitCost[i][0] + (i + 1) * (0 + 1));
        }
        for(int i = 1;i < m;i ++){
            for(int j = 1;j < n;j ++){
                if(i == m - 1 && j == n - 1){
                    goto FINAL;
                }
                int enter_cost = waitCost[i][j] + (i + 1) * (j + 1);
                int upp_cost = F[i - 1][j] + enter_cost;
                int left_cost = F[i][j - 1] + enter_cost;
                F[i][j] = min(upp_cost, left_cost);
            }
        }
        FINAL:
        if(m > 1 && n > 1){
            F[m - 1][n - 1] = min(F[m - 2][n - 1] + m * n, F[m - 1][n - 2] + m * n);
        }
        return F[m - 1][n - 1] + 1;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}