/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // same as top/bottom view
        if(!root) return {};
        
        unordered_map<int, vector<int>> map;
        int xmin=0, xmax=0;

        vector<tuple<int, int, int>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto [curr, coords]= q.front(); q.pop();
            auto [x, y]= coords;
            
            nodes.push_back({x, y, curr->val});
            if(curr->left) q.push({curr->left, {x-1, y+1}});
            if(curr->right) q.push({curr->right, {x+1, y+1}});
        }

        sort(nodes.begin(), nodes.end());
        int prevX= INT_MIN;

        vector<vector<int>> solutions;
        for(auto [x, y, val]: nodes){
            if(x!= prevX){
                solutions.push_back({});
                prevX= x;
            }
            solutions.back().push_back(val);
        }
        return solutions;
    }
};