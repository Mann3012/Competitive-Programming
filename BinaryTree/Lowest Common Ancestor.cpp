#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

const TreeNode* lowestCommonAncestor(const TreeNode* root,const TreeNode* p,const TreeNode* q){
    if(!root || root==p || root==q){
        return root;
    }
    const TreeNode* left=lowestCommonAncestor(root->left,p,q);
    const TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(!left){
        return right;
    }else if(!right){
        return left;
    }
    return root;
}