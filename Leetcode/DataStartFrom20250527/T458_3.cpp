#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    char processStr(string s, long long k) {
        // 如果字符是?小写 英文字母，则将其添加到 result 中。
        // 字符 '*' 会?删除 result 中的最后一个字符（如果存在）。
        // 字符 '#' 会?复制?当前的 result 并追加到其自身后面。
        // 字符 '%' 会?反转?当前的 result。
        // 返回最终字符串 result 中第 k?个字符（下标从 0 开始）。
        // 如果 k 超出 result 的下标索引范围，则返回 '.'。    
        long long index = -1;
        for(auto item : s){
            if(item >= 'a' && item <= 'z'){
                ++ index;
            }
            else if(item == '*'){
                if(index >= 0){
                    -- index;
                }
            }
            else if(item == '#'){
                index = 2 * index + 1;
            }
            else if(item == '%'){
                ;
            }

        }
        if(k > index){
            return '.';
        }
        int sz = s.size();
        for(int i = sz - 1;i >= 0;i --){
            char item = s[i];
            if(item >= 'a' && item <= 'z'){
                if(k == index){
                    return item;
                }
                index --;
            }
            else if(item == '*'){
                index ++;
            }
            else if(item == '#'){
                index = (index + 1) / 2 - 1;
                k = k <= index ? k : k - index - 1;
            }
            else if(item == '%'){
                k = index - k;
            }
        }
        return '/';
    }
};

int main(){

    return 0;
}