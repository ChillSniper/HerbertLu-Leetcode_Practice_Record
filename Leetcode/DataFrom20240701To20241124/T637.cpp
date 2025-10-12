#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
//#define BFSWay
#define DFSWay

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
};

#ifdef DFSWay
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        auto sum = vector<double>();
        auto level = vector<int>();
        DFS(sum, level, 0, root);
        int Len = sum.size();
        for(int i = 0;i < Len;i ++){
            ans.push_back(sum[i] / (level[i] * 1.0));
        }
        return ans;
    }
    void DFS(vector<double>& sum, vector<int>& level, int depth, TreeNode* p){
        if(!p) return ;
        if(depth < level.size()){
            sum[depth] += p->val;
            level[depth] ++;
        } else{
            sum.push_back(p->val);
            level.push_back(1);
        }
        DFS(sum, level, depth + 1, p->left);
        DFS(sum, level, depth + 1, p->right);
    }
};
#endif

#ifdef BFSWay
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int Len = dq.size();
            double sum = 0;
            int StoreLen = Len;
            while (Len --)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                sum += node->val;
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
            ans.push_back(sum / (StoreLen * 1.0));
        }
        return ans;
    }
};
#endif