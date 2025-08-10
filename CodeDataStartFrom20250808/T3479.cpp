#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define Test

class Segment_Tree {
public:
    Segment_Tree(const vector<int>& arr) {
        int n = arr.size();
        max_val.resize(n * 4);
        Build(arr, 1, 0, n - 1);
    }
    bool FindFirstWithUpdate(int i, int l, int r, int x) {
        if(max_val[i] < x) {
            return -1;
        }
        if(l == r) {
            max_val[i] = -1;
            return l;
        }
        int mid = (l + r) >> 1;
        int val = FindFirstWithUpdate(i << 1, l, mid, x);
        if(val == -1) {
            val = FindFirstWithUpdate(i << 1 | 1, mid + 1, r, x);
        }
        pushup(i);
        return val != -1;
    }
private:
    void Build(const vector<int>& arr, int i, int l, int r) {
        if(l == r) {
            max_val[i] = arr[l];
            return ;
        }
        int mid = (l + r) >> 1;
        Build(arr, i << 1, l, mid);
        Build(arr, i << 1 | 1, mid + 1, r);
        pushup(i);
    }
    void pushup(int u) {
        max_val[u] = max(max_val[u << 1], max_val[u << 1 | 1]);
    }
    vector<int> max_val;
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        Segment_Tree tr(baskets);
        int ans = 0, n = fruits.size();
        for (int i = 0;i < (int)fruits.size();i ++) {
            bool flag = tr.FindFirstWithUpdate(1, 0, n - 1, fruits[i]);
            if(flag == false) {
                ++ ans;
            }
        }
        return ans;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}