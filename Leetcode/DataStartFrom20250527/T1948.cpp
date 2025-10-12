#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
#define Test

struct TrieNode{
    unordered_map<string, TrieNode*> son;
    string cur_name;
    bool Is_Deleted = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for(auto& path : paths){
            TrieNode* cur = root;
            for(auto& s : path){
                if(!cur->son.count(s)){
                    cur->son[s] = new TrieNode();
                }
                cur = cur->son[s];
                cur->cur_name = s;
            }
        }

        unordered_map<string, TrieNode*> record;
        auto expr = [&](this auto&& expr, TrieNode* node) -> string {
            if(node->son.empty()){
                return node->cur_name;
            }
            vector<string> tmp;
            for(auto& [_, son] : node->son){
                tmp.emplace_back("(" + expr(son) + ")");
            }
            ranges::sort(tmp);
            string sub_tree;
            for(auto& t : tmp){
                sub_tree += t;
            }
            if(record.count(sub_tree)){
                record[sub_tree]->Is_Deleted = true;
                node->Is_Deleted = true;
            }
            else{
                record[sub_tree] = node;
            }
            return node->cur_name + sub_tree;
        };

        for(auto& [_, son] : root->son){
            expr(son);
        }
        vector<vector<string>> ans;
        vector<string> path;

        auto dfs = [&](this auto&& dfs, TrieNode* node) -> void {
            if(node->Is_Deleted){
                return ;
            }
            path.push_back(node->cur_name);
            ans.push_back(path);
            for (auto& [_, son] : node->son) {
                dfs(son);
            }
            path.pop_back();
        };

        for (auto& [_, son] : root->son) {
            dfs(son);
        }

        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}