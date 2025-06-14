#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
实际上这道题想不出来的问题在于，没有想到，或者说“不敢”去维护新的节点去保持链表节点之间的前后关系，
然后就对链表的节点移动操作束手无策
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* Spe = new ListNode(0, head);
        ListNode* LastFinished = head, *CurDeal = head->next;
        while (CurDeal)
        {
            ListNode* tmp = CurDeal->next;
            if(CurDeal->val >= LastFinished->val){
                LastFinished = CurDeal;
                CurDeal = tmp;
            } else{
                ListNode* pre = Spe, *cur = Spe->next;
                for(;cur != CurDeal;){
                    if(cur->val >= CurDeal->val){
                        pre->next = CurDeal;
                        CurDeal->next = cur;
                        LastFinished->next = tmp;
                        CurDeal = tmp;
                        break;
                    } else{
                        pre = pre->next;
                        cur = cur->next;
                    }
                }
            }
        }
        return Spe->next;
    }
};