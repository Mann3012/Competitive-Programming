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

void inorderDriver(vector<int>&inorder,const Node*root){
    if(root==nullptr) return;
    inorderDriver(inorder,root->left);
    inorder.push_back(root->data);
    inorderDriver(inorder,root->right);
}
vector<int> inorderTraversal(const Node* root){
    vector<int> inorder;
    inorderDriver(inorder,root);
    return inorder;
}
void preorderDriver(vector<int>&preorder,const Node*root){
    if(root==nullptr) return;
    preorder.push_back(root->data);
    preorderDriver(preorder,root->left);
    preorderDriver(preorder,root->right);
}
vector<int> preorderTraversal(const Node* root){
    vector<int> preorder;
    preorderDriver(preorder,root);
    return preorder;
}



void postorderDriver(vector<int>&postorder,const Node*root){
    if(root==nullptr) return;
    postorderDriver(postorder,root->left);
    postorderDriver(postorder,root->right);
    postorder.push_back(root->data);
}
vector<int> postorderTraversal(const Node* root){
    vector<int> postorder;
    postorderDriver(postorder,root);
    return postorder;
}