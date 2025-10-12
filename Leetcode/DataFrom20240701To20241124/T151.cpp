#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
//#define Way1
#define Way2
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        #ifdef Way1
        reverse(s.begin(), s.end());
        s += " ";
        int SlowPointer = 0;
        int FastPointer = 0;
        int flag = 0;
        int RevLeft = -1;
        int RevRight = s.length();
        while (FastPointer < s.length())
        {
            if(isalnum(s[FastPointer]) && !flag){
                RevLeft = FastPointer;
                flag = 1;
            } else if(s[FastPointer] == ' ' && flag){
                RevRight = FastPointer - 1;
                for(int i = RevLeft;i <= RevRight;i ++)
                    s[SlowPointer ++] = s[i];
                reverse(s.begin() + SlowPointer - 1 + RevLeft - RevRight, s.begin() + SlowPointer);
                s[SlowPointer ++] = ' ';
                flag = 0;
            }
            FastPointer ++;
        }
        s.resize(SlowPointer - 1);
        return s;
        #endif
        #ifdef Way2
        deque<string> dq;
        string temp, ans;
        s += " ";
        int Pointer = 0;
        while (Pointer < s.length())
        {
            if(s[Pointer] == ' '){
                if(temp.size()) dq.push_back(temp);
                temp = "";
            } else if(isalnum(s[Pointer])){
                temp += s[Pointer];
            }
            Pointer ++;
        }
        while (!dq.empty())
        {
            ans += dq.back();
            ans += " ";
            dq.pop_back();
        }
        ans.resize(ans.size() - 1);
        return ans;
        #endif
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    string s;
    std::getline(cin, s);
    Solution fuck;
    string ans = fuck.reverseWords(s);
    std::cout << ans;
    std::cout << "#";
    return 0;
}