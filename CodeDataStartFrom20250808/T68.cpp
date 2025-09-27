#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 弯弯绕绕的，这个题意叙述真的和史一样
        // 实际上本题的意图是对文本进行再分配，然后注意对空格和最后一行的特殊处理。
        // 暂时不太想写这坨东西，留到晚上吧
        vector<string> ans;
        int cur_sz = 0, st_index = 0, n = words.size();
        for (int i = 0;i < n;++ i) {
            st_index = i;
            cur_sz = 0;
            int j = i, Limit_Width = maxWidth + 1, WORD_LEN = 0;
            string tmp = "";
            while (j < n && (cur_sz + (int)words[j].size() + 1) <= Limit_Width)
            {
                WORD_LEN += words[j].size();
                cur_sz += (int)words[j].size() + 1;
                ++ j;
            }
            i = j - 1;
            int cnt = j - st_index;
            int BLANK_SZ = maxWidth - WORD_LEN;
            int avg = cnt == 1 ? 0 : BLANK_SZ / (cnt - 1);
            vector<int> StoreForBlank(cnt - 1, 0);
            if(cnt == 1) {
                StoreForBlank.push_back(0);
            }
            for (int fk = 0;fk < cnt - 1;fk ++) {
                StoreForBlank[fk] = avg;
            }
            int p = BLANK_SZ - avg * (cnt - 1);
            if(cnt > 1) {
                for (int fk = 0;fk < p;fk ++) {
                    ++ StoreForBlank[fk];
                }
            }
            else {
                StoreForBlank[0] = BLANK_SZ;
            }
            for (int fk = st_index;fk < j - 1;fk ++) {
                tmp += words[fk];
                for (int k = 0;k < StoreForBlank[fk - st_index];k ++) {
                    tmp += " ";
                }
            }
            tmp += words[j - 1];
            if(cnt == 1) {
                for (int k = 0;k < BLANK_SZ;k ++) {
                    tmp += " ";
                }
            }
            ans.push_back(tmp);
        }
        string fk = "";
        for (int i = st_index;i < n;i ++) {
            fk += words[i];
            if(i != n - 1)
                fk += " ";
        }
        int fk_sz = fk.size();
        for (int i = 0;i < (int)maxWidth - fk_sz;i ++) {
            fk += " ";
        }
        ans[ans.size() - 1] = fk;
        return ans;
    }
};


int main() {

    return 0;
}