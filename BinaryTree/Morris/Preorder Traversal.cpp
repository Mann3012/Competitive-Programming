#include<bits/stdc++.h>
using namespace std;

/*
Problem: Binary Tree Preorder Traversal (Morris)

Approach:
Morris Traversal (Threaded Binary Tree)

Time Complexity: O(n)
Auxiliary Space: O(1)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> morrisPreorderTraversal(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr=root;
    while (curr) {
        if(!curr->left){
            preorder.push_back(curr->data);
            curr=curr->right;
        }else{
            TreeNode* pred=curr->left;
            while(pred->right && pred->right != curr){
                pred=pred->right;
            }

            if (!pred->right) {
                pred->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }else{
                pred->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return preorder;
}