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
    bool isCousins(TreeNode* root, int x, int y) {
        // cousin= same depth, different parent
        // Approach: BFS with parent check
        if(!root || root->val==x || root->val==y) return false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s= q.size();
            bool foundOne= false;

            for(int i=0; i<s; i++){
                TreeNode* curr= q.front(); q.pop();

                if(curr->left){
                    int val= curr->left->val;
                    if(val==x || val==y){
                        if(curr->right && (curr->right->val==x || curr->right->val==y)){
                            return false;
                        }if(foundOne) return true;  // Early exit
                        foundOne= true;
                    }
                    q.push(curr->left);
                }
                if(curr->right){
                    int val= curr->right->val;
                    if(val==x || val==y){
                        if(foundOne) return true;  // Early exit
                        foundOne= true;
                    }
                    q.push(curr->right);
                }
            }
            if(foundOne) return false;
        }
        return false;
    }
};