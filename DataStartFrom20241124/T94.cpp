#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
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
    vector<int> inorderTraversal(TreeNode* root) {
        get_ans(root);
        return ans;
    }
    void get_ans(TreeNode* root){
        if(!root) return ;
        get_ans(root->left);
        ans.push_back(root->val);
        get_ans(root->right);
    }
private:
    vector<int> ans;
};

int main(){
    #ifdef Test

    #endif
    return 0;
}