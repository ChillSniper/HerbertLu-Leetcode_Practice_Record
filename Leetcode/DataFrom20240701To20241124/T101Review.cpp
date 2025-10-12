#include <iostream>
#include <cstdio>
#include <vector>
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return IsSame(root->left, root->right);
    }
    bool IsSame(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if(!l && r || l && !r || l->val != r->val) return false;
        return IsSame(l->left, r->right) && IsSame(l->right, r->left);
    }
};
int main(){
    return 0;
}