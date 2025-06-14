#include <iostream>
#include <cstdio>
#include <algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode();
        ListNode* p = Head;
        int x = 0;
        while (l1 && l2)
        {
            x = l1->val + l2->val + x;
            ListNode* tmp = new ListNode(x % 10);
            x /= 10;
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            x += l1->val;
            l1 = l1->next;
            p->next = new ListNode(x % 10);
            x /= 10;
            p = p->next;
        }
        while (l2)
        {
            x += l2->val;
            l2 = l2->next;
            p->next = new ListNode(x % 10);
            x /= 10;
            p = p->next;
        }
        return Head->next;
    }
};
int main(){

    return 0;
}