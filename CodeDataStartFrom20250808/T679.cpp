#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        // 这题打暴力的操作难度在于，运算符可以排列组合重新组合。但是，括号该怎么添加上去？
        // 或者可以采取选择两个数然后执行操作的方式，
        // 但是新的问题又来了，怎么从一个数组中获得选取两个数的所有情况？   
        // 对于这个问题，采取的方式是直接暴力枚举
        int n = cards.size();
        vector<double> record(n, 0);
        for (int i = 0;i < n;i ++) {
            record[i] = cards[i];
        }
        return Dfs(record);
    }
private:
    const double eps = 1e-5;
    bool Dfs(vector<double> cards) {
        int n = cards.size();
        if(n == 1) {
            return abs(cards[0] - 24) <= eps;
        }
        vector<double> record;
        for (int i = 0;i < n;i ++) {
            for (int j = i + 1;j < n;j ++) {
                double a = cards[i], b = cards[j];
                record = {a + b, a - b, b - a, a * b};
                if(abs(a) >= eps) {
                    record.push_back(b / a);
                }
                if(abs(b) >= eps) {
                    record.push_back(a / b);
                }
                auto new_cards = cards;
                new_cards.erase(new_cards.begin() + j);
                int sz = record.size();
                for (int k = 0;k < sz;k ++) {
                    new_cards[i] = record[k];
                    if(Dfs(new_cards)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}