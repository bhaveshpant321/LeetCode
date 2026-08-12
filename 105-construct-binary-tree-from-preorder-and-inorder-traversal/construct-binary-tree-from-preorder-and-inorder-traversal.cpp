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
    // map inorder for fast index lookup
    unordered_map<int, int> map;    // {value, index in inorder}
    int index=0;

    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start>end) return nullptr;
        int rootVal= preorder[index++];
        TreeNode* root= new TreeNode(rootVal);
        int mid= map[rootVal];
        root->left= helper(preorder, start, mid-1);
        root->right= helper(preorder, mid+1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder gives root, inorder seperates left and right children
        TreeNode* root= new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        
        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]]=i;
        }
        return helper(preorder, 0, inorder.size()-1);
    }
};