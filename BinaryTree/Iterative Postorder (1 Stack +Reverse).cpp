#include<bits/stdc++.h>
using namespace std;

/*
Problem: Binary Tree Postorder Traversal (Iterative)
LeetCode: 145

Traversal:
Left -> Right -> Root

Approach:
Modified preorder (Root -> Right -> Left), then reverse the result.

Time Complexity: O(n)
Auxiliary Space: O(h)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> postorderIterative(const TreeNode* root) {
    vector<int> postorder;
    if(root==nullptr) return postorder;

    stack<const TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        const TreeNode*  node=st.top();
        st.pop();

        postorder.push_back(node->data);

        if(node->left) 
            st.push(node->left);
        if(node->right) 
            st.push(node->right);
    }
    reverse(postorder.begin(),postorder.end());
    return postorder;
}