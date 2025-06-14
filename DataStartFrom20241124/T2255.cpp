#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_set<string> st;
        int sz = words.size(), cnt = 0;
        for(int i = 0;i < sz;i ++){
            if(st.count(words[i])){
                cnt ++; 
            }
            else if(Judge(words[i], s)){
                cnt ++;
                st.insert(words[i]);
            }
        }
        return cnt;
    }
private:
    bool Judge(string& text, string& s){
        int text_size = text.size(), s_size = s.size();
        if(text_size > s_size)
            return false;
        for(int i = 0;i < text_size;i ++){
            if(text[i] != s[i])
                return false;
        }
        return true;
    }
};

#define Test

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}