#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
int j[300];
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        j['a'] = j['e'] = j['i'] = j['o'] = j['u'] = 1;
        // cout << f(word, k) << endl << f(word, k + 1) << endl;
        return f(word, k) - f(word, k + 1);
    }
private:
    ll f(string word, int k){
        int sz = word.size();
        int l = 0, r = 0, ans = 0, cnt = 0;
        unordered_map<char, int> ump;
        for(;l <= r && r < sz;){
            if(j[word[r]]){
                ump[word[r]] ++;
            }
            else{
                cnt ++;
            }
            r ++;
            while (cnt >= k && ump.size() == 5)
            {
                if(j[word[l]]){
                    ump[word[l]] --;
                    if(ump[word[l]] == 0)
                        ump.erase(word[l]);
                }
                else{
                    cnt --;
                }
                l ++;
            }
            ans += l;
        }
        return ans;
    }
};

#define Test
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string t = "aeiou";
    int k = 0;
    Solution s;
    cout << s.countOfSubstrings(t, k);
    return 0;
}