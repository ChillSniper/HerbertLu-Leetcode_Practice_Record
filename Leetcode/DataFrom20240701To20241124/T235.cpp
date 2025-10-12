#include <iostream>
#include <cstdio>
using namespace std;
//#define RecursiveWay
#define IterateWay

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
#ifdef IterateWay
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root)
        {
            if(root->val >= p->val && root->val <= q->val || root->val >= q->val && root->val <= p->val) return root;
            if(root->val > p->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root->val > p->val && root->val < q->val || root->val > q->val && root->val < p->val) return root;
        if(root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        return nullptr;
    }
};
#endif