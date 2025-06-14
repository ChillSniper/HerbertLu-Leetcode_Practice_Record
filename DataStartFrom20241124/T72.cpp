#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz_1 = word1.size(), sz_2 = word2.size();
        word1 = " " + word1;
        word2 = " " + word2;
        vector<vector<int>> f(sz_1 + 1, vector<int>(sz_2 + 1, 0));
        // 1. insert 
        // 2. delete
        // 3. replace
        // ��������������Ʒ��̸���ôд������
        // ����һ�����⣬��ֵ����ô�趨������
        // �Ǹ�insert������״̬ת���е����뵽
        // f[i][0]��ɾ������
        // f[0][i] �����Ӳ���
        // f[0][0] = 1;
        for(int i = 1;i <= sz_1;i ++)
            f[i][0] = i;
        for(int j = 1;j <= sz_2;j ++)
            f[0][j] = j;
        for(int i = 1;i <= sz_1;i ++){
            for(int j = 1;j <= sz_2;j ++){
                if(word1[i] == word2[j]){
                    f[i][j] = f[i - 1][j - 1];
                }
                else{
                    f[i][j] = MinNum(f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]) + 1;
                    // ע�⵽������ֲ�����Ӧ��ת��״̬���̣�����һ��Ҫ���͸��
                }
            }
        }
        return f[sz_1][sz_2];
    }
private:
    int MinNum(int a, int b, int c){
        return min(min(a, b), min(b, c));
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}