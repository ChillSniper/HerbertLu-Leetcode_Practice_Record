#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//#define RecursiveWay
#define IterateWay

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef IterateWay
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root)
        {
            if(root->val == val) return root;
            if(root->val < val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
#endif