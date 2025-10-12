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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 如何对vector数组进行切割？
        // 直接使用它本身带有的那个函数，但是要注意到， 如果要创建含有n个元素的数组，应当是
        // vector<int> arr(ori.begin(), ori.begin() + n); // 注意后一个参数是ori.begin() + n !!! 而不是 ori.begin() + n - 1
        if(inorder.size() == 0) return nullptr;
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[n - 1]);
        int position = n;
        for(int i = 0;i < n;i ++){
            if(inorder[i] == postorder[n - 1]){position = i; break;}
        }
        // deal with inorder array   [0, position - 1], [position + 1, n - 1]
        // deal with postorder array [0, position - 1], [position, n - 2]
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + position);
        vector<int> inorderright(inorder.begin() + position + 1, inorder.begin() + n);
        vector<int> postLeft(postorder.begin(), postorder.begin() + position);
        vector<int> postRight(postorder.begin() + position, postorder.begin() + n - 1);
        root->left = buildTree(inorderLeft, postLeft);
        root->right = buildTree(inorderright, postRight);
        return root;
    }
};