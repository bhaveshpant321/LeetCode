/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string& s){
        if(!root){
            s+="#,";
            return;
        }

        s+= to_string(root->val)+",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(const string& s, int& idx){
        if(idx>= s.size()) return nullptr;
        if(s[idx]=='#'){
            idx+=2; // skip "#,"
            return nullptr;
        }

        string val="";
        while(s[idx]!=',') val+=s[idx++];
        idx++;  // skip ","
        TreeNode* node= new TreeNode(stoi(val));
        node->left= deserializeHelper(s, idx);
        node->right= deserializeHelper(s, idx);
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return deserializeHelper(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));