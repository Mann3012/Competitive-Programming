#include<bits/stdc++.h>
using namespace std;

/*
Algorithm: Recursive Binary Tree Traversals

Functions:
- inorderTraversal()
- preorderTraversal()
- postorderTraversal()

Time Complexity: O(n)
Space Complexity: O(h) (recursion stack)
*/

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void inorderHelper(vector<int>&inorder,const Node*root){
    if(root==nullptr) return;
    inorderHelper(inorder,root->left);
    inorder.push_back(root->data);
    inorderHelper(inorder,root->right);
}
vector<int> inorderTraversal(const Node* root){
    vector<int> inorder;
    inorderHelper(inorder,root);
    return inorder;
}
void preorderHelper(vector<int>&preorder,const Node*root){
    if(root==nullptr) return;
    preorder.push_back(root->data);
    preorderHelper(preorder,root->left);
    preorderHelper(preorder,root->right);
}
vector<int> preorderTraversal(const Node* root){
    vector<int> preorder;
    preorderHelper(preorder,root);
    return preorder;
}
void postorderHelper(vector<int>&postorder,const Node*root){
    if(root==nullptr) return;
    postorderHelper(postorder,root->left);
    postorderHelper(postorder,root->right);
    postorder.push_back(root->data);
}
vector<int> postorderTraversal(const Node* root){
    vector<int> postorder;
    postorderHelper(postorder,root);
    return postorder;
}