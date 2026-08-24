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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) str.append("#,");
            else{
                str.append(to_string(curr->val)+',');
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> qs;
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
if(str == "#") return NULL;

TreeNode* root = new TreeNode(stoi(str));
        qs.push(root);
        while(!qs.empty()){
            TreeNode* node = qs.front();
            qs.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left =NULL;
            }
            else{
             TreeNode* leftNode =   new TreeNode(stoi(str));
             node->left = leftNode;
             qs.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right =NULL;
            }
            else{
             TreeNode* rightNode =   new TreeNode(stoi(str));
             node->right = rightNode;
             qs.push(rightNode);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));