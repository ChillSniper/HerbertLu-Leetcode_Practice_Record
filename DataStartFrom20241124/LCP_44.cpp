#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int numColor(TreeNode* root) {
        PreOrder(root);
        return cnt;
    }
    void PreOrder(TreeNode* root){
        if(!root) return ;
        if(!st.count(root->val)){
            cnt ++;
            st.insert(root->val);
        }
        PreOrder(root->left);
        PreOrder(root->right);
    }
private:
    int cnt;
    unordered_set<int> st;
};