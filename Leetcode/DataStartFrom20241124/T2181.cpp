#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// #define MyWay
#define TwoPointerWay
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#ifdef TwoPointerWay
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* PreHead = new ListNode();
        ListNode* slw = PreHead, *fst;
        int cur = 0;
        for(fst = head->next;fst;fst = fst->next){
            if(fst->val == 0){
                ListNode* tmp = new ListNode(cur);
                cur = 0;
                slw->next = tmp;
                slw = slw->next;
                tmp->next = fst->next;
            } else{
                cur += fst->val;
            }
        }
        return PreHead->next;
    }
};
#endif

#ifdef MyWay
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int CurrentSum = 0;
        ListNode* LastNode, *CurNode;
        LastNode = nullptr;
        CurNode = head;
        while (CurNode)
        {
            if(CurNode->val == 0 && CurrentSum){
                ListNode* tmp = new ListNode(CurrentSum);
                LastNode->next = tmp;
                tmp->next = CurNode;
                CurrentSum = 0;
                LastNode = CurNode;
                CurNode = CurNode->next;
            }else if(CurNode->val){
                CurrentSum += CurNode->val;
                LastNode->next = CurNode->next;
                CurNode = CurNode->next;
            }else{
                LastNode = CurNode;
                CurNode = CurNode->next;
            }
        }
        CurNode = head;
        LastNode = nullptr;
        while(CurNode){
            if(CurNode->val == 0 && LastNode){
                LastNode->next = CurNode->next;
                CurNode = CurNode->next;
            } else if(CurNode->val == 0 && !LastNode){
                CurNode = CurNode->next;
                head = CurNode;
            } else{
                LastNode = CurNode;
                CurNode = CurNode->next;
            }
        }
        return head;
    }
};
#endif