#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define Test

struct info{
    int index;
    char ch;
};

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int cnt1 = 0, cnt2 = 0;
        if(x >= y){
            cnt1 = OpString(s, "ab");
            cnt2 = OpString(s, "ba");
        } else{
            cnt2 = OpString(s, "ba");
            cnt1 = OpString(s, "ab");
        }
        return cnt1 * x + cnt2 * y;
    }
private:
    int OpString(string& s, string target){
        int cnt = 0, n = s.size();
        vector<int> flag(n, 1);
        stack<info> store;
        for(int i = 0;i < n;i ++){
            if(s[i] != target[1]){
                store.push({i, s[i]});
            }
            else{
                if(!store.empty() && store.top().ch == target[0]){
                    info t = store.top();
                    store.pop();
                    ++ cnt;
                    flag[t.index] = 0;
                    flag[i] = 0;
                }
            }
        }
        int fs, sl;
        for(fs = 0, sl = 0;fs < n && sl < n;){
            if(flag[fs] == 1){
                s[sl ++] = s[fs ++];
            }
            else{
                ++ fs;
            }
        }
        s.resize(sl);
        return cnt;
    }
};