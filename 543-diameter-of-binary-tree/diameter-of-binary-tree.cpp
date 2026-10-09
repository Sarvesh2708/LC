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
    int ans=0;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lefht = height(root->left);
        int ritht = height(root->right);
        ans = max(lefht+ritht,ans);
        return 1+max(lefht,ritht);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};