#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//#define RecursiveWay
#define IterationWay

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#ifdef RecursiveWay
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int Len = preorder.size();
        for(int i = 0;i < Len;i ++){
            mp[inorder[i]] = i;
        }
        return MyBuildTree(preorder, inorder, 0, Len - 1, 0, Len - 1);
    }
private:
    unordered_map<int, int> mp;
    TreeNode* MyBuildTree(const vector<int>& preorder, const vector<int>& inorder, int PreLf, int PreRg, int InLf, int InRg){
        if(PreLf > PreRg) return nullptr;
        TreeNode* root = new TreeNode;
        int num = preorder[PreLf];
        int k = FindPositonOfRoot(num);
        root->val = num;
        root->left = MyBuildTree(preorder, inorder, PreLf + 1, k - 1 - InLf + 1 + PreLf, InLf, k - 1);
        root->right = MyBuildTree(preorder, inorder, PreLf + k - InLf + 1, PreRg, k + 1, InRg);
        return root;
    }
    int FindPositonOfRoot(int val){
        return mp[val];
    }
};
#endif

#ifdef IterationWay
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // 这边的麻烦在于构造的节点会发生重复，这该如何解决？
    // 解决方案是直接一步到位，不采用记录节点信息，而是直接栈记录节点本身
        if(!preorder.size()) return nullptr;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        int InorderIndex = 0;
        for(int i = 1;i < preorder.size();i ++){
            TreeNode* node = s.top();
            if(s.top()->val != inorder[InorderIndex]){
                TreeNode* p = new TreeNode(preorder[i]);
                node->left = p;
                s.push(p);
            } else{
                while (!s.empty() && s.top()->val == inorder[InorderIndex])
                {
                    node = s.top(); s.pop(); InorderIndex ++;
                }
                TreeNode* p = new TreeNode(preorder[i]);
                node->right = p;
                s.push(p);
            }
        }
        return root; 
    }
};
#endif