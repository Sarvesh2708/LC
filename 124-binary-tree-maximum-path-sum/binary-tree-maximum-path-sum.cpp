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
    int maxvaluepath = INT_MIN;
    int getmaxpathvals(TreeNode* root){
        if(root==NULL)return 0;

        int maxleftpath = max(0, getmaxpathvals(root->left));
        int maxrightpath = max(0, getmaxpathvals(root->right));


        maxvaluepath = max(maxvaluepath,root->val+maxleftpath+maxrightpath);
        return root->val + max(maxleftpath, maxrightpath);

    }
public:
    int maxPathSum(TreeNode* root) {
        getmaxpathvals(root);
        return maxvaluepath;
    }
};