#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        vector<int> Nxt(m + 10, 0);
        s = s + s;
        Nxt[0] = -1;
        for(int i = 0;i < m;i ++){
            int k = Nxt[i];
            while (k >= 0 && goal[i] != goal[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        int n = s.size();
        for(int i = 0, j = 0;i < n;){
            if(j < 0 || s[i] == goal[j]){
                i ++;
                j ++;
                if(j == m) return true;
            }
            if(s[i] != goal[j]){
                j = Nxt[j];
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    s.rotateString("abcde", "cdeab");
    return 0;
}