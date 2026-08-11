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
    void convert(TreeNode* root, int& runningSum){
        if(!root) return;
        convert(root->right, runningSum);
        runningSum+= root->val;
        root->val= runningSum;
        convert(root->left, runningSum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        // greater tree= for each node: og value+sum of all keys greater than it
        // Approach: right->node->left, keep adding the rolling sum as you go back
        int runningSum=0;
        convert(root, runningSum);
        return root;
    }
};