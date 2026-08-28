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

TreeNode* bstFromPreorder(vector<int>& preorder,int &i,int maxval){
    if(i==preorder.size() || preorder[i]>maxval) return NULL;
    TreeNode* curr = new TreeNode(preorder[i++]);
    curr->left = bstFromPreorder(preorder,i,curr->val);
    curr->right = bstFromPreorder(preorder,i,maxval);
    return curr;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return bstFromPreorder(preorder,i,INT_MAX);
    }
};