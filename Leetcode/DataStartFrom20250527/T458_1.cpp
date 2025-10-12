#include <bits/stdc++.h>
using namespace std;
#define Test

const int N = 1e5 + 10;
char result[N];

class Solution {
public:
    string processStr(string s) {
//         如果字符是 小写 英文字母，则将其添加到 result 中。
// 字符 '*' 会?删除 result 中的最后一个字符（如果存在）。
// 字符 '#' 会?复制?当前的 result 并?追加?到其自身后面。
// 字符 '%' 会?反转?当前的 result。?leetcode
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