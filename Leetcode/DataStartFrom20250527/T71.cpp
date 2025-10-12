#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
#define Test

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> address;
        int sz = path.size();
        for(int i = 0;i < sz;i ++){
            int ori_i = i;
            if(path[i] == '.'){
                int j = i;
                while (j < sz && path[j] == '.')
                {
                    ++ j;
                }
                int sz_of_point = j - i;
                i = j - 1;
                if(!(j == sz || path[j] == '/')){
                    i = j;
                    goto A;
                }
                if(sz_of_point == 1){
                    continue;
                }
                else if(sz_of_point == 2){
                    if(!address.empty()){
                        address.pop();
                    }
                }
                else{
                    string cur_add = path.substr(ori_i, sz_of_point);
                    address.push(cur_add);
                }
            }
            else if(path[i] == '/'){
                int j = i;
                while (j < sz && path[j] == '/')
                {
                    ++ j;
                }
                i = j - 1;
            }
            else{
            A:
                int j = i;
                while (j < sz && !(path[j] == '/'))
                {
                    ++ j;
                }
                int len = j - ori_i;
                i = j - 1;
                string cur_add = path.substr(ori_i, len);
                address.push(cur_add);
            }
        }
        string ans;
        if(address.empty()){
            ans = "/";
            return ans;
        }
        while (!address.empty())
        {
            string cur = address.top();
            address.pop();
            ans = "/" + cur + ans;
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string path = "/HkOPFethUYRJYwGjzHMe/rJteBUS///IsKEnIQJ/../../hGXBMGFqtOjs/rmSJGOpIwm/CLuUcSXPiwjsK///uAmXcWR/./tTrlKBgzBlNEwF/OOpDjmMoTvaedK///./YYjtE///cH/KOmxKcGmWg/qGCOBeWiABLFqcIOmz/////./maSVbpF/./CWFbBs/qMzsrWxv/.././vvUmYui///KCVaRfmLpZOzberV/VHOA/jphGcKrSF/kJkDRYKtpUosUWVbD///gclGacfgDoPGdiXxPWyc/MZIcVQZzab/DIGNdzzS/qBPDkxjWjEQlv/Njfre/./hxoM/mKKOwBVEWZwjagOuWi/UuLHfsWzeWi/../QuopYsUtqgnqAiXwE/qgokdsKKhosJhdBiSjA/..///ANrXgVcSNejG/FIfSyTz/.///UZlMfMXBUmuCDhiVQf///kqdiy/aRxweiOpLcczy/RPed/e/zbO/././M/NxCFeiNOJI/../qfBhtXbBFuRBPQrYpTx///tZhVBcmIMlnygAKHKdcT///rQllOCPKsfmXOdMT/./xqXODEft/dOqZbqJ/uCii///../../fDWbSnpMzPd///./PS/.././//HIQJuNdVfdlpqBKA/wo/.././OhBzBcujoxcpY/EHrtJtqIsnhIUkqh///./../WKPXCkCl/FEncfxOdTdcBPMUAS/OYcSyadfthTntUAsjUm/././iTURgskcGXkmDKWLcis/KvNnwUvQcCBJ/UCNcxJzeOdaX/././..///tX///DfxuGi/";
    Solution s;
    cout << s.simplifyPath(path);
    return 0;
}