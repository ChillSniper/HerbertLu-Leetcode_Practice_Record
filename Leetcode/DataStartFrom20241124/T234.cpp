#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        deque<int> dq;
        while (head)
        {
            dq.push_back(head->val);
            head = head->next;
        }
        while (dq.size() > 1)
        {
            int a = dq.front(); dq.pop_front();
            int b = dq.back(); dq.pop_back();
            if(a != b) return false;
        }
        return true;
    }
};

int main(){

    return 0;
}