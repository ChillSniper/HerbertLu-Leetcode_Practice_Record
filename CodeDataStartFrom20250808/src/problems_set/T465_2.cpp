#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> ans;
    int cur;
public:
    vector<int> minDifference(int n, int k) {
        // 
        vector<int> record;
        int t = n;
        cur = 0x3f3f3f3f;
        for (int i = 2;i <= n;i ++) {
            if(t == 1) {
                break;
            }
            if(IsPrime(i)) {
                while (t % i == 0)
                {
                    record.push_back(i);
                    t /= i;   
                }
            }
        }    
        sort(record.begin(), record.end());
        int sz = record.size();
        for (auto item : record) {
            cout << item << " ";
        }
        if(sz == k) {
            return record;
        }
        if(sz < k) {
            while((int)record.size() < k) {
                record.push_back(1);
            }
            return record;
        }   
        Dfs(record, k);
        return ans;
    }
private:
    void Dfs(vector<int>& record, int k) {
        sort(record.begin(), record.end());
        int n = record.size();
        if(n == k) {
            if(record[n - 1] - record[0] < cur) {
                cur = record[n - 1] - record[0];
                ans = record;
            }
            return ;
        }
        for (int i = 1;i < n;i ++) {
            int new_val = record[0] * record[i];
            int r_0 = record[0], r_i = record[i], r_lst = record[n - 1];
            // vector<int> new_arr = record;
            record[0] = new_val;
            swap(record[i], record[n - 1]);
            record.resize(n - 1);
            Dfs(record, k);
            record.resize(n);
            record[0] = r_0;
            record[i] = r_i;
            record[n - 1] = r_lst;
        }
    }
    bool IsPrime(int x) {
        if(x <= 1) 
            return false;
        for (int i = 2;i * i <= x;i ++) {
            if (x % i == 0) 
                return false;
        }
        return true;
    }
};

#define Test

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n = 7560, k = 5;
    Solution s;
    vector<int> ans = s.minDifference(n, k);
    cout << endl;
    for (auto item : ans) {
        cout << item << " ";
    }
    return 0;
}