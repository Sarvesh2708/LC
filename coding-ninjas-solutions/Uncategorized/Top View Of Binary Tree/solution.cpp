#include <bits/stdc++.h>

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    queue<pair<TreeNode<int> *,int>>q;
    map<int,int>mpp;
    vector<int> ans;

    if(root==NULL) return ans;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int> * node = it.first;
        int line = it.second;
        if(mpp.find(line)==mpp.end()) mpp[line]=node->data;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}










// #include <bits/stdc++.h>



// vector<int> getTopView(TreeNode<int> *root)
// {
//     // Write your code here.
//     vector<int> ans;
//     if(root==NULL) return ans;

//     queue<pair<TreeNode<int> *,int>> q;
//     map<int,int> mp;
//     q.push({root,0});
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
//         TreeNode<int> * node = it.first;
//         int line = it.second;
//         if(mp.find(line)==mp.end()) mp[line] = node->data;
//         if(node->left){
//             q.push({node->left,line-1});
//         }
//         if(node->right){
//             q.push({node->right,line+1});
//         }

//     }

//     for(auto p:mp){
//         ans.push_back(p.second);
//     }
//     return ans;


    
// }



// /************************************************************

//     Following is the TreeNode class structure:

//     template <typename T>
//     class TreeNode
//     {
//     public:
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T dat)
//         {
//             this->data = dat;
//             left = NULL;
//             right = NULL;
//         }
//     };

// ************************************************************/


