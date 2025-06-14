#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

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
    int maxProduct(TreeNode* root) {
        Dfs(root);
        GetFather(root);
        all = Sum[root];
        GetMax(root);
        return (int)(ans % (long long)(1e9 + 7));
    }
private:
    long long ans = 0;
    void GetFather(TreeNode* root){
        if(!root) return ;
        if(root->left){
            father[root->left] = root;
            GetFather(root->left);
        }
        if(root->right){
            father[root->right] = root;
            GetFather(root->right);
        }
    }
    void GetMax(TreeNode* root){
        if(!root) return ;
        GetMax(root->left);
        GetMax(root->right);
        int tmp = Sum[root];
        if(father.count(root)){
            tmp += all - Sum[root];
        }
        if(root->left){
            ans = max(ans, (long long)Sum[root->left] * (long long)(tmp - Sum[root->left]));
        }
        if(root->right){
            ans = max(ans, (long long)Sum[root->right] * (long long)(tmp - Sum[root->right]));
        }
    }
    int all;
    unordered_map<TreeNode*, int> Sum;
    unordered_map<TreeNode*, TreeNode*> father;
    void Dfs(TreeNode* root){
        if(!root) return ;
        Dfs(root->left);
        Dfs(root->right);
        Sum[root] = root->val;
        if(root->left)
            Sum[root] += Sum[root->left];
        if(root->right)
            Sum[root] += Sum[root->right];
    }
};