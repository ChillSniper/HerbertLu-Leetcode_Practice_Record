#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define Test

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        // An interesting problem
        // solved on 2025-01-02
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    // printf("%c", 'a' + 17);
    return 0;
}