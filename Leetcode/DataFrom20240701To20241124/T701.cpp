#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* p = new TreeNode(val);
            return p;
        }
        if(!root->left && root->val > val){
            TreeNode* p = new TreeNode(val);
            root->left = p;
            return root;
        }
        if(!root->right && root->val < val){
            TreeNode* p = new TreeNode(val);
            root->right = p;
            return root;
        }
        if(val < root->val)
            insertIntoBST(root->left, val);
        if(val > root->val)
            insertIntoBST(root->right, val);
        return root;
    }
};