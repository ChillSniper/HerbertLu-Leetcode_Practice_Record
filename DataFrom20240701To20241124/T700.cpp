#include <iostream>
#include <cstdio>
using namespace std;
//#define RecursiveWay
#define IterateWay

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
        if(!root || root->val == val) return root;
        while (root)
        {
            if(root->val == val) return root;
            if(root->val > val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        if(val > root->val) return searchBST(root->right, val);
        if(val < root->val) return searchBST(root->left, val);
    }
};
#endif