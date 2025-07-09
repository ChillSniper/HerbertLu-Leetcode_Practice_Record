#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

typedef long long ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        // ������鷳�ĵط����ڣ�����ַ�֮��ļ����� �� k ֮��Ĺ�ϵ��
        // �е���dp�����ǲ�֪����ô��
        // �ܸ��ӣ����ǻ��ǵ�����д��ȥ
        vector<int> Record;
        ll ans = 1;
        int sz = word.size(), tmp_cnt = 0;
        if(sz < k){
            return 0;
        }
        for(int i = 0;i < sz;i ++){
            if(i == 0 || word[i] == word[i - 1]){
                ++ tmp_cnt;
            }
            else{
                ans = (ans * tmp_cnt) % MOD;
                -- k;
                if(tmp_cnt > 1){
                    Record.push_back(tmp_cnt);
                }
                else{
                    // ɶ�����ø�
                }
                tmp_cnt = 1;
            }
        }
        ans = ans * tmp_cnt % MOD;
        -- k;
        if(tmp_cnt > 1){
            Record.push_back(tmp_cnt);
        }
        
        // dp����ʵ�����Ƕ�״̬�ĵ���
        // ����������֮�����ڶ��״̬֮��Ĺ�ϵ�ǳ����ҡ�
        int m = Record.size();
        // target = f[m][k - 1]
        // ��i����Ʒ��c��
        // f[i][j] = sum(L = 0 -> c) f[i - 1][j - L]
        // equal to f[i][j] = sum(L = max(j - c, 0), j) f[i - 1][L]
        // so next ? 
        vector<int> s(k + 1, 0);
        vector f(m + 1, vector<int>(k, 0));
        fill(f[0].begin(), f[0].end(), 1);
        for(int i = 0;i < m;i ++){
            int c = Record[i];
            for(int j = 0;j <= k - 1;j ++){
                s[j + 1] = s[j] + f[i][j];
            }
            for(int j = 0;j <= k - 1;j ++){
                f[i + 1][j] = s[j + 1] - s[max(j - c, 0)]; 
            }
        }
        return (ans - f[m][k - 1]) % MOD;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.possibleStringCount("aabbccdd", 7);
    return 0;
}