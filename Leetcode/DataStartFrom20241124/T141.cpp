#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fst = head, * slw = head;
        while (fst && slw)
        {
            if(fst->next) fst = fst->next->next;
            else fst = fst->next;
            slw = slw->next;
            if(fst == slw) return true;
        }
        return false;
    }
};

int main(){
    return 0;
}