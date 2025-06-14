#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define Test
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    string beginStr, endStr;
    cin >> beginStr >> endStr;
    unordered_set<string> st;
    for(int i = 0;i < n;i ++){
        string tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    unordered_map<string, int> mp;
    deque<string> dq;
    dq.push_back(beginStr);
    mp[beginStr] = 1;
    while (!dq.empty())
    {
        string cur = dq.front(); dq.pop_front();
        int path = mp[cur];
        for(int i = 0;i < cur.size();i ++){
            char ch = cur[i];
            for(int j = 0;j < 26;j ++){
                cur[i] = 'a' + j;
                if(cur == endStr){
                    cout << path + 1;
                    return 0;
                }
                if(st.count(cur) && !mp.count(cur)){
                    mp[cur] = path + 1;
                    dq.push_back(cur);
                }
            }
            cur[i] = ch;
        }
    }
    cout << 0;
    return 0;
}