#include <iostream>
#include <vector>
using namespace std;
//#define Way1
//#define Way2
#define Test

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> Next(needle.size());
        GetNext(&Next[0], needle);
        int j = -1;
        for(int i = 0;i < haystack.size();i ++){
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = Next[j];
            }
            if(haystack[i] == needle[j + 1]){
                j ++;
            }
            if(j == needle.size() - 1){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }

private:
    void GetNext( int* Next, string& needle ){
        int j = -1;
        Next[0] = j;
        for(int i = 1;i < needle.size();i ++){
            while (needle[i] != needle[j + 1] && j >= 0)
            {
                j = Next[j];
            }
            if(needle[j + 1] == needle[i]){
                j ++;
            }
            Next[i] = j;
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    #ifdef Test
        string haystack, needle;
        cin >> haystack >> needle;
        Solution s;
        int ans = s.strStr(haystack, needle);
        std::cout << ans;
    #endif
    return 0;
}