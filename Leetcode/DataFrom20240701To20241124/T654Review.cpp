#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Single stack
        int len = nums.size();
        vector<int> LeftArr(len, -1), RightArr(len, -1);
        stack<int> st;
        vector<TreeNode*> arr(len);
        for(int i = 0;i < len;i ++){
            arr[i] = new TreeNode(nums[i]);
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                RightArr[st.top()] = i;
                st.pop();
            }
            if(!st.empty())
                LeftArr[i] = st.top();
            st.push(i);
        }
        TreeNode* root = nullptr;
        for(int i = 0;i < len;i ++){
            if(LeftArr[i] == -1 && RightArr[i] == -1) root = arr[i];
            else if(LeftArr[i] == -1 || RightArr[i] != -1 && nums[RightArr[i]] <= nums[LeftArr[i]])
                arr[RightArr[i]]->left = arr[i];
            else
                arr[LeftArr[i]]->right = arr[i];
        }
        return root;
    }
};
int main(){
    return 0;
}