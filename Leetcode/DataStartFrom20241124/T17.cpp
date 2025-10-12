#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        Init();
        string cur = "";
        Dfs(digits, 0, cur);
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<int, vector<char>> ump;
    void Init(){
        ump[2] = {'a', 'b', 'c'}; ump[3] = {'d', 'e', 'f'};
        ump[4] = {'g', 'h', 'i'}; ump[5] = {'j', 'k', 'l'};
        ump[6] = {'m', 'n', 'o'}; ump[7] = {'p', 'q', 'r', 's'};
        ump[8] = {'t', 'u', 'v'}; ump[9] = {'w', 'x', 'y', 'z'};
    }
    void Dfs(string digits, int index, string cur){
        int sz = digits.size();
        if(index >= sz){
            ans.push_back(cur);
            return ;
        }
        for(int i = index;i < sz;i ++){
            int num = digits[i] - '0';
            if(ump.count(num)){
                vector<char> op = ump[num];
                int sz_op = op.size();
                for(auto item : op){
                    string x = cur + item;
                    Dfs(digits, i + 1, x);
                }
            }
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}