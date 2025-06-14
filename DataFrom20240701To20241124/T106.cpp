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
        // ��ζ�vector��������и
        // ֱ��ʹ����������е��Ǹ�����������Ҫע�⵽�� ���Ҫ��������n��Ԫ�ص����飬Ӧ����
        // vector<int> arr(ori.begin(), ori.begin() + n); // ע���һ��������ori.begin() + n !!! ������ ori.begin() + n - 1
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