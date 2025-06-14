#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = word.size(), n = sequence.size();
        vector<int> Nxt(m + 10, 0), match(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i < m;i ++){
            int k = Nxt[i];
            while (k >= 0 && word[i] != word[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        for(int i = 0, j = 0;i < n;){
            if(j < 0 || sequence[i] == word[j]){
                i ++; j ++;
                if(j == m){
                    match[i] = 1;
                    j = Nxt[j];
                }
            }
            if(i >= n) break;
            if(sequence[i] != word[j]){
                j = Nxt[j];
            }
        }
        int MaxCnt = 0;
        for(int i = 0;i <= n;i ++){
            if(i - m >= 0 && match[i] && match[i - m]){
                match[i] = match[i - m] + 1;
            }
            MaxCnt = max(MaxCnt, match[i]);
        }
        return MaxCnt;
    }
};

int main(){
    Solution s;
    cout << s.maxRepeating("ababc", "ba");
    return 0;
}