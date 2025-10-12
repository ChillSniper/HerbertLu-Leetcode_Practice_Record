#include <bits/stdc++.h>
using namespace std;
#define Test

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while (head)
        {
            val *= 2;
            val += head->val;
            head = head->next;
        }
        return val;
    }
};

int main(){

    return 0;
}