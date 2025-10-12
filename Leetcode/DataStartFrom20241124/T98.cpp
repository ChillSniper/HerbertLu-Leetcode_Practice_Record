#include <iostream>
#include <cstdio>
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
        bool isValidBST(TreeNode* root) {
            GetPreorder(root);
            int sz = x.size();
            for(int i = 1;i < sz;i ++){
                if(x[i] <= x[i - 1]) return false;
            }
            return true;
        }
    private:
        void GetPreorder(TreeNode* root){
            if(!root) return ;
            GetPreorder(root->left);
            x.push_back(root->val);
            GetPreorder(root->right);
        }
        vector<int> x;
};
int main(){
    return 0;
}