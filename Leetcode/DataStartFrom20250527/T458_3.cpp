#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    char processStr(string s, long long k) {
        // ����ַ���?Сд Ӣ����ĸ��������ӵ� result �С�
        // �ַ� '*' ��?ɾ�� result �е����һ���ַ���������ڣ���
        // �ַ� '#' ��?����?��ǰ�� result ��׷�ӵ���������档
        // �ַ� '%' ��?��ת?��ǰ�� result��
        // ���������ַ��� result �е� k?���ַ����±�� 0 ��ʼ����
        // ��� k ���� result ���±�������Χ���򷵻� '.'��    
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