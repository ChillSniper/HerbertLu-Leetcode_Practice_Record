#include <iostream>
#include <cstdio>
#include <vector>
//#include <stack>
//#define RecursiveAlgorithm
//#define NonRecursiveAlgorithm
#define NonRecursiveAlgorithmType2
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#ifdef RecursiveAlgorithm
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* p = root;
        postorderTraversal(p->left);
        postorderTraversal(p->right);
        ans.push_back(p->val);
        return ans;
    }
private:
    vector<int> ans;
};
#endif

#ifdef NonRecursiveAlgorithm
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* p = root, *Pre = nullptr;
        stack<TreeNode*> s;
        while (1)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            if(s.empty()) return ans;
            p = s.top();
            if(p->right == nullptr || p->right == Pre){
                s.pop();
                ans.push_back(p->val);
                Pre = p;
                p = nullptr;
            } else{
                p = p->right;
            }
        }
        
    }
private:
    vector<int> ans;
};
#endif

#ifdef NonRecursiveAlgorithmType2
const int MaxSize = 1e2 + 10;
class Stack{
public:
    void Push(TreeNode* p, int i){Node[++top] = p; Cnt[top] = i;}
    TreeNode* Pop(int& i){i = Cnt[top]; return Node[top --];}
    bool Empty(){return top == -1;}
    bool Full(){return top == MaxSize - 1;}
private:
    int top = -1;
    TreeNode* Node[MaxSize];
    int Cnt[MaxSize];
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        Stack s;
        if(root) s.Push(root, 1);
        while (!s.Empty())
        {
            TreeNode* p;
            int i;
            p = s.Pop(i);
            if(i == 1){s.Push(p, 2); if(p->left){s.Push(p->left, 1);}}
            else if(i == 2){s.Push(p, 3); if(p->right){s.Push(p->right, 1);}}
            else if(i == 3){ans.push_back(p->val);}
        }
        return ans;
    }
private:
    vector<int> ans;
};
#endif

int main(){
    return 0;
}