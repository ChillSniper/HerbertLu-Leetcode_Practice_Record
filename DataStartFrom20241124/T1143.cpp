#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz_1 = text1.size(), sz_2 = text2.size();
        // �����������ʱ��д���������㷨����Ҳ�����������ں���������...
        //������һ��������������ö������
        // Ҳ����˵ �������զ����㷨��...
        // 
        vector<vector<int>> f(sz_1 + 1, vector<int>(sz_2 + 1, 0));
        text1 = " " + text1;
        text2 = " " + text2;
        for(int i = 1;i <= sz_1;i ++){
            for(int j = 1;j <= sz_2;j ++){
                if(text1[i] == text2[j]){
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else{
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[sz_1][sz_2];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}