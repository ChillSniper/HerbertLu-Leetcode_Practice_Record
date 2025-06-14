#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Pre = new ListNode(0, head);
        ListNode* fst = Pre, *slw = Pre, *before = Pre;
        while (n --)
        {
            fst = fst->next;
        }
        while (fst)
        {
            fst = fst->next;
            before = slw;
            slw = slw->next;
        }
        before->next = slw->next;
        return Pre->next;
    }
};

int main(){

    return 0;
}