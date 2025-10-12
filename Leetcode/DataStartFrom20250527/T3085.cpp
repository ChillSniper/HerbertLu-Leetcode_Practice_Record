#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

// ppbbvvvnnn
// 2233
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> ump;
        for(auto ch : word){
            ump[ch] ++;
        }
        // 问题是要将值域范围限制在k内，这个就很难搞
        vector<int> record;
        for(auto item : ump)
            record.push_back(item.second);
        sort(record.begin(), record.end());
        int sz = record.size();
        vector<int> Pre(sz, 0), Suf(sz, 0);
        Pre[0] = record[0];
        for(int i = 1;i < sz;i ++){
            Pre[i] = Pre[i - 1] + record[i];
        }
        Suf[sz - 1] = record[sz - 1];
        for(int i = sz - 2;i >= 0;i --){
            Suf[i] = Suf[i + 1] + record[i];
        }
        int MinNum = 0x3f3f3f3f;
        for(int i = 0, j = 0;i < sz && j < sz;i ++){
            while (j + 1 < sz && record[j + 1] - record[i] <= k)
            {
                j ++;
            }
            int tmp_target = 0;
            int lf = i - 1, ri = j + 1;
            if(lf >= 0){
                tmp_target += Pre[lf];
            }
            if(ri < sz){
                tmp_target += Suf[ri] - (k + record[i]) * (sz - ri);
            }
            MinNum = min(MinNum, tmp_target);
        }
        return MinNum;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}