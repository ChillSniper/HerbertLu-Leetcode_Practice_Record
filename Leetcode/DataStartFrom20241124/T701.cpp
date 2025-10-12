#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// #define MyWay
#define RootPointerWay

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef MyWay
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        if(root->val == val) return root;
        if(root->val < val){
            if(!root->right){
                root->right = new TreeNode(val);
                return root;
            } else insertIntoBST(root->right, val);
        } else {
            if(!root->left){
                root->left = new TreeNode(val);
                return root;
            } else insertIntoBST(root->left, val);
        }
        return root;
    }
};
#endif