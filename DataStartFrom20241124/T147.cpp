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
ʵ����������벻�������������ڣ�û���뵽������˵�����ҡ�ȥά���µĽڵ�ȥ��������ڵ�֮���ǰ���ϵ��
Ȼ��Ͷ�����Ľڵ��ƶ����������޲�
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