#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
#define Test
const int N = 1e3 + 10;
char str1[N], str2[N], ans1[10], ans2[10];
unordered_map<char, int> mp;
unordered_map<int, char> dt;
int GetNum(char* s, char* ans);
void Init();
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Init();
    cin.getline(str1, N);
    cin.getline(str2, N);
    int num1 = GetNum(str1, ans1);
    int num2 = GetNum(str2, ans2);
    char ans[10] = {};
    int index = 0, num = num1 + num2;
    while (num > 0)
    {
        char ch = dt[num % 16];
        ans[index ++] = ch;
        num /= 16;
    }
    printf("HD_");
    printf("%s", ans1);
    if(strlen(ans1) == 0) printf("0");
    printf("+HD_");
    printf("%s", ans2);
    if(strlen(ans2) == 0) printf("0");
    printf("=HD_");
    int n = strlen(ans);
    if(n == 0) printf("0");
    else{
        for(int i = n - 1;i >= 0;i --) printf("%c", ans[i]);
    }
    return 0;
}
void Init(){
    for(char i = '0';i <= '9';i ++){ mp[i] = i - '0'; dt[i - '0'] = i;}
    for(char i = 'A';i <= 'F';i ++) {mp[i] = i - 'A' + 10; dt[i - 'A' + 10] = i;}
}
int GetNum(char* s, char* ans){
    int cnt = 0, cur = 0;
    for(int i = 0;i < strlen(s);i ++){
        if(mp.count(s[i]) && (cur > 0 || cur == 0 && s[i] != '0')){
            cur = cur * 16 + mp[s[i]];
            ans[cnt ++] = s[i];
            if(cnt == 5) break;
        }
    }
    return cur;
}