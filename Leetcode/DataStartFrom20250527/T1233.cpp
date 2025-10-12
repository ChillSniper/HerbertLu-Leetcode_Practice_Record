#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int n = folder.size(), cp = -1;
        vector<int> flag(n, 1);
        if(Judge(folder[0]) == false){
            flag[0] = 0;
        }
        else{
            cp = 0;
        }
        for(int i = 1;i < n;i ++){
            bool t = Judge(folder[i]);
            if(t == false){
                flag[i] = 0;
                cp = -1;
            }
            
            if(cp >= 0 && folder[i].find(folder[cp]) != -1){
                int len = folder[cp].size();
                int pos = folder[i].find(folder[cp]);
                if(pos != 0){
                    cp = i;
                    continue;
                }
                if(folder[i][len] == '/'){
                    flag[i] = 0;
                }
                else{
                    cp = i;
                }
            }
            else{
                cp = i;
            }
        }
        vector<string> ans;
        for(int i = 0;i < n;i ++){
            if(flag[i] == 1){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
private:
    bool Judge(string s){
        int n = s.size(), cnt = 0;
        for(int i = 0;i < n;i ++){
            if(s[i] == '/'){
                if(i != 0 && cnt == 0){
                    return false;
                }
                cnt = 0;
            }
            else{
                ++ cnt;
            }
        }
        return cnt > 0;
    }
};

int main(){
    return 0;
}