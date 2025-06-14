#include <iostream>
#include <vector>
#include <cstring>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root);
        return ans;
    }
    void DFS(TreeNode* root){
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right){
            string s = to_string(tmp[0]);
            int size = tmp.size();
            for(int i = 1;i < size;i ++){
                s += "->"; s += to_string(tmp[i]);
            }
            ans.push_back(s);
        }
        if(root->left){DFS(root->left);}
        if(root->right){DFS(root->right);}
        ans.pop_back();
    }
private:
    vector<string> ans;
    vector<int> tmp;
};

int main(){
    return 0;
}