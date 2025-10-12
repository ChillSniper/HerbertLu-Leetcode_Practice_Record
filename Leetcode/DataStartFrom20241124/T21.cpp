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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Head = new ListNode();
        ListNode* p = Head;
        while (list1 && list2)
        {
            if(list1->val < list2->val){
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } 
            else{
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        if(list1) p->next = list1;
        else p->next = list2;
        return Head->next;
    }
};

int main(){

    return 0;
}