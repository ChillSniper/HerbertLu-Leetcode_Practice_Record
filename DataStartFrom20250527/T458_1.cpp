#include <bits/stdc++.h>
using namespace std;
#define Test

const int N = 1e5 + 10;
char result[N];

class Solution {
public:
    string processStr(string s) {
//         ����ַ��� Сд Ӣ����ĸ��������ӵ� result �С�
// �ַ� '*' ��?ɾ�� result �е����һ���ַ���������ڣ���
// �ַ� '#' ��?����?��ǰ�� result ��?׷��?����������档
// �ַ� '%' ��?��ת?��ǰ�� result��?leetcode
        string ans;
        memset(result, 0, sizeof result);
        int index = -1;
        for(auto& item : s){
            if(item >= 'a' && item <= 'z'){
                result[++ index] = item;
            }
            else if(item == '*'){
                if(index >= 0){
                    -- index;
                }
            }
            else if(item == '#'){
                for(int j = 0;j <= index;j ++){
                    result[j + index + 1] = result[j];
                }
                index = 2 * index + 1;
            }
            else if(item == '%'){
                for(int i = 0, j = index;i < j;++ i, -- j){
                    swap(result[i], result[j]);
                }
            }
        }
        for(int i = 0;i <= index;i ++){
            ans += result[i];
        }
        return ans;
    }
};

int main(){
    return 0;
}