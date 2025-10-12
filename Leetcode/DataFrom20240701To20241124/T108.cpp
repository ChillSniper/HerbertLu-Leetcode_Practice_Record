#include <iostream>
#include <cstdio>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // divided the array
        if(nums.size() <= 0) return nullptr; 
        int n = nums.size();
        int positon = n / 2;
        // [0, position - 1] and [position + 1, n - 1]
        TreeNode* root = new TreeNode(nums[positon]);
        vector<int> arrLeft(nums.begin(), nums.begin() + positon);
        vector<int> arrRight(nums.begin() + positon + 1, nums.end());
        root->left = sortedArrayToBST(arrLeft);
        root->right = sortedArrayToBST(arrRight);
        return root;
    }
};
int main(){
    return 0;
}