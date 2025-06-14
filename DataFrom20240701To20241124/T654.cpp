#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
//#define BruteWay
#define MonotonicWay

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef MonotonicWay
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        vector<TreeNode*> node(n);
        vector<int> lf(n, -1), ri(n, -1);
        stack<int> st;
        for(int i = 0;i < n;i ++){
            node[i] = new TreeNode(nums[i]);
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                ri[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) lf[i] = st.top();
            st.push(i);
        }
        TreeNode* root = nullptr;
        for(int i = 0;i < n;i ++){
            if(lf[i] == -1 && ri[i] == -1){
                root = node[i];
            }
            else if(ri[i] == -1 ||(lf[i] != -1 && nums[lf[i]] < nums[ri[i]])){
                node[lf[i]]->right = node[i];
            }
            else node[ri[i]]->left = node[i];
        }
        return root;
    }
};
#endif

#ifdef BruteWay
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        int maxNum = 0xc0c0c0c0, n = nums.size(), position = n;
        for(int i = 0;i < n;i ++){
            if(maxNum < nums[i]){
                maxNum = nums[i];
                position = i;
            }
        }
        TreeNode* root = new TreeNode(maxNum);
        // divided the array [0, position - 1], [position + 1, n - 1]
        vector<int> LeftArr(nums.begin(), nums.begin() + position);
        vector<int> RightArr(nums.begin() + position + 1, nums.begin() + n);
        root->left = constructMaximumBinaryTree(LeftArr);
        root->right = constructMaximumBinaryTree(RightArr);
        return root;
    }
};
#endif
