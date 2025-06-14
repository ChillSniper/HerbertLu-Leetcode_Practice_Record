#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define Test

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root] = nullptr;
        GetFather(root);
        TreeNode* recode = p;
        unordered_set<TreeNode*> st;
        while (recode)
        {
            st.insert(recode);
            recode = father[recode];
        }
        recode = q;
        while (recode)
        {
            if(st.count(recode)) return recode;
            recode = father[recode];
        }
        return nullptr;
    }
private:
    unordered_map<TreeNode*, TreeNode*> father;
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
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}