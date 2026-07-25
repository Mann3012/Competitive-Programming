#include<bits/stdc++.h>
using namespace std;

/*
Problem: Binary Tree Preorder Traversal (Iterative)
LeetCode: 144

Traversal:
Root -> Left -> Right

Time Complexity: O(n)
Auxiliary Space: O(h)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

vector<int> preorderIterative(const TreeNode* root) {
        
        vector<int> preorder;
        if(root==nullptr) return preorder;

        stack<const  TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            const TreeNode* node=st.top();
            st.pop();

            preorder.push_back(node->data);

            if(node->right) 
                st.push(node->right);

            if(node->left) 
                st.push(node->left);
        }
        return preorder;
}