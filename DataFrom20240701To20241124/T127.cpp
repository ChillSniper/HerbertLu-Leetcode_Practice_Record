#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        mp[beginWord] = 1;
        unordered_set<string> st;
        for(auto i : wordList) st.insert(i);
        deque<string> dq;
        dq.push_back(beginWord);
        while (!dq.empty())
        {
            string tmp = dq.front(); dq.pop_front();
            int path = mp[tmp];
            for(int i = 0;i < tmp.size();i ++){
                char ch = tmp[i];
                for(int j = 0;j < 26;j ++){
                    tmp[i] = 'a' + j;
                    if(st.count(tmp) && !mp.count(tmp)){
                        if(endWord == tmp) return path + 1;
                        dq.push_back(tmp);
                        mp[tmp] = path + 1;
                    }
                }
                tmp[i] = ch;
            }
        }
        return 0;
    }
};

int main(){
    return 0;
}