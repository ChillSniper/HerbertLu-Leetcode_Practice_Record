#include <bits/stdc++.h>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // ����������ѣ���Ҫ�����벻����ά����˵�Ȼ����Ҷ˵�������ۣ�����֮�еĹ�ϵ�쳣�ĸ���
        vector<vector<int>> record(n + 1);
        for (auto& item : conflictingPairs) {
            int a = item[0], b = item[1];
            if(a > b){
                swap(a, b);
            }
            record[a].push_back(b);
        }
        long long ans = 0;
        vector<long long> Extra(n + 10);
        vector<int> cur = {n + 1, n + 1};
        for (int i = n;i >= 1;i --) {
            cur.insert(cur.end(), record[i].begin(), record[i].end());
            sort(cur.begin(), cur.end());
            cur.resize(2);
            ans += cur[0] - i;
            Extra[cur[0]] += cur[1] - cur[0];
        }
        ans += ranges::max(Extra);
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}