#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;
#define Test

char sequence[4] = {'A', 'C', 'T', 'G'};
struct P{
    string s;
    int num;
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> store_bank;
        for(auto& item : bank){
            store_bank.insert(item);
        }
        unordered_set<string> history;
        history.insert(startGene);
        int len = startGene.size();
        deque<P> dq;
        dq.push_back({startGene, 0});
        int Cur_changeTime = 0;
        while (dq.size())
        {
            
            P cur_p = dq.front(); dq.pop_front();
            string cur = cur_p.s;
            int cur_num = cur_p.num;
            for(int i = 0;i < len;i ++){
                for(int j = 0;j < 4;j ++){
                    int target = sequence[j];
                    string tmp = cur;
                    if(tmp[i] == target){
                        continue;
                    }
                    tmp[i] = target;
                    if(history.count(tmp)){
                        continue;
                    }
                    if(store_bank.count(tmp)){
                        history.insert(tmp);
                        dq.push_back({tmp, cur_num + 1});
                    }
                    if(tmp == endGene && store_bank.count(tmp)){
                        return cur_num + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}