#include <iostream>
#include <cstdio>

 // Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return CompareTree(p, q);
    }
    bool CompareTree(TreeNode* p, TreeNode* q){
        if(!p && q || !q && p) return false;
        if(!p && !q) return true;
        if(p->val != q->val) return false;
        bool Judge1 = CompareTree(p->left, q->left);
        bool Judge2 = CompareTree(p->right, q->right);
        return Judge1 && Judge2;
    }
};