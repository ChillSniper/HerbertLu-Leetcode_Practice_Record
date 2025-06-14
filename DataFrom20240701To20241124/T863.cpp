#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <deque>
#include <unordered_map>
using namespace std;
//#define MakeFatherWay
#define BuildGraphWay
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef BuildGraphWay
class Solution {
public:
    Solution(){
        memset(head, -1, sizeof(head));
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        int vis[N] = {0};
        Dfs(root);
        deque<int> dq;
        dq.push_back(target->val);
        vis[target->val] = 1;
        while (!dq.empty() && k >= 0)
        {
            int size = dq.size();
            while (size --)
            {
                int p = dq.front(); dq.pop_front();
                if(!k) {ans.push_back(p); continue;}
                for(int b = head[p];b != -1;b = ne[b]){
                    int q = e[b];
                    if(!vis[q]){
                        vis[q] = 1;
                        dq.push_back(q);
                    }
                }
            }
            k --;
        }
        return ans;
    }
    void Dfs(TreeNode* root){
        if(!root) return;
        if(root->left){
            AddEdges(root->val, root->left->val);
            AddEdges(root->left->val, root->val);
            Dfs(root->left);
        }
        if(root->right){
            AddEdges(root->val, root->right->val);
            AddEdges(root->right->val, root->val);
            Dfs(root->right);
        }
    }
    void AddEdges(int a, int b){
        // building the edge a->b
        e[idx] = b;
        ne[idx] = head[a];
        head[a] = idx ++;
    }
private:
    static const int N = 5e2 + 10, M = N * 3;
    int idx = 0, head[N], e[M], ne[M]; 
};
#endif

#ifdef MakeFatherWay
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 实际上这道题的问题在于如何去往父节点去搜索目标值
        // 同时还有一个问题在于避免重复搜索
        GetFather(root);
        FindNode(k, 0, nullptr, target);
        return ans;
    }
private:
    void GetFather(TreeNode* root){
        if(!root) return;
        if(root->left) {father[root->left->val] = root; GetFather(root->left);}
        if(root->right) {father[root->right->val] = root; GetFather(root->right);}
    }
    void FindNode(int k, int distance, TreeNode* pre, TreeNode* cur){
        if(distance == k && cur){
            ans.push_back(cur->val);
            return ;
        }
        if(father[cur->val] && father[cur->val] != pre){
            FindNode(k, distance + 1, cur, father[cur->val]);
        }
        if(cur->left && cur->left != pre)
            FindNode(k, distance + 1, cur, cur->left);
        if(cur->right && cur->right != pre)
            FindNode(k, distance + 1, cur, cur->right);
    }
    unordered_map<int, TreeNode*> father;
    vector<int> ans;
};
#endif
int main(){

    return 0;
}