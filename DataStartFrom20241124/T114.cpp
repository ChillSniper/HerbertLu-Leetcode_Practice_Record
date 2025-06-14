#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
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
    void flatten(TreeNode* root) {
        p = root;
        Dfs(root);
    }
private:
    void Dfs(TreeNode* root){
        if(!root) return;
        TreeNode* r = root->right;
        TreeNode* l = root->left;
        p = root;
        p->right = p->left;
        p->left = nullptr;
        Dfs(l);
        p->right = r;
        Dfs(r);
    }
    TreeNode* p;
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}