#include<bits/stdc++.h>
using namespace std;

/*
Problem: Binary Tree Inorder Traversal (Iterative)
LeetCode: 94

Traversal:
Left -> Root -> Right

Time Complexity: O(n)
Auxiliary Space: O(h)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

vector<int> inorderIterative(const TreeNode* root){
    vector<int> inorder;
    const TreeNode* node=root;
    stack<const TreeNode*> st;
    while(!st.empty() || node){
        if(node){
            st.push(node);
            node=node->left;
        }else{
            const TreeNode* temp=st.top();
            st.pop();
            inorder.push_back(temp->data);
            node=temp->right;
        }
    }
    return inorder;
}