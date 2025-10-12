#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        Delete(root, key);
        return root;
    }
    void Delete(TreeNode* &root, int k){
        if(!root) return ;
        if(root->val < k) Delete(root->right, k);
        else if(root->val > k) Delete(root->left, k);
        else if(root->left && root->right){
            TreeNode* p = root->right;
            while(p->left) p = p->left;
            root->val = p->val;
            Delete(root->right, p->val);
        }
        else{
            TreeNode* p = root;
            root = (root->left) ? root->left : root->right;
            delete p; p = nullptr;
        }
    }
};