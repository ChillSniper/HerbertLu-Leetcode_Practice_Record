#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a.find(b) != string::npos) return 1;
        else if((a + a).find(b) != string::npos) return 2;
        int n = a.size();
        vector<int> Nxt(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i < n;i ++){
            int k = Nxt[i];
            while(k >= 0 && a[i] != a[k]){
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        n = b.size();
        int m = a.size();
        vector<int> Match(n + 10, 0);
        for(int i = 0, j = 0;i < n;){
            if(j < 0 || b[i] == a[j]){
                i ++; j ++;
                if(j == m){
                    j = Nxt[j];
                    Match[i - 1] = 1;
                }
            }
            if(i >= n) break;
            if(b[i] != a[j]){
                j = Nxt[j];
            }
        }
        for(int i = 0;i < n;i ++){
            if(Match[i] && i - m >= 0 && Match[i - m]){
                Match[i] = Match[i - m] + 1;
            }
        }
        int position = -1, MaxNum = 0;
        for(int i = n - 1;i >= 0;i --){
            if(Match[i] > MaxNum){
                position = i;
                MaxNum = Match[i];
            }
        }
        if(position == -1){
            if((a + a).find(b) == string::npos) return -1;
            else return 2;
        }
        int ans = 0;
        int st = position - Match[position] * m;
        int index = m - 1;
        if(st >= 0) ans += 1;
        while (st >= 0 && index >= 0)
        {
            if(b[st] != a[index]) return -1;
            st --;
            index --;
        }
        index = 0;
        int fn = position + 1;
        if(fn < n) ans += 1;
        while (index < m && fn < n)
        {
            if(b[fn] != a[index]) return false;
            fn ++;
            index ++;
        }
        return Match[position] + ans;
    }
private:
    
};