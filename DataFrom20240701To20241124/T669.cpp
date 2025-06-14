#include <iostream>
#include <cstdio>
//#define RecursiveWay
#define IterateWay
using namespace std;

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root ->val >  high))
        {
            if(root->val < low) root = root->right;
            else if(root->val > high) root = root->left;
        }
        TreeNode* p = root;
        while (p)
        {
            if(p->left && p->left->val < low){
                p->left = p->left->right;
            }
            else p = p->left;
        }
        p = root;
        while (p)
        {
            if(p->right && p->right->val > high){
                p->right = p->right->left;
            }
            else p = p->right;
        }
        return root;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val >= low && root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        } else if(root->val < low){
            root->left = nullptr;
            root = trimBST(root->right, low, high);
        } else if(root->val > high){
            root->right = nullptr;
            root = trimBST(root->left, low, high);
        }
        return root;
    }
};
#endif