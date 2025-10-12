#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        int d = 0;
        if(!root) return d;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            d ++;
            int size = dq.size();
            while (size --)
            {
                TreeNode* p = dq.front();
                dq.pop_front();
                if(p->left == nullptr && p->right == nullptr) return d;
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
        }
        return d;
    }
};