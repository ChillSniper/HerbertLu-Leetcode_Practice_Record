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
        int kthSmallest(TreeNode* root, int k) {
            GetPreOrder(root);
            return x[k - 1];
        }
    private:
        vector<int> x;
        void GetPreOrder(TreeNode* root){
            if(!root) return ;
            GetPreOrder(root->left);
            x.push_back(root->val);
            GetPreOrder(root->right);
        }
    };
int main(){
    return 0;
}