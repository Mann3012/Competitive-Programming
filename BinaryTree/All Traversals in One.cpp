#include<bits/stdc++.h>
using namespace std;

/*
Problem: Preorder, Inorder and Postorder Traversal in One Traversal

Approach:
Use a single stack storing (node, state):
1 -> Process preorder and visit left subtree
2 -> Process inorder and visit right subtree
3 -> Process postorder and remove node

Time Complexity: O(n)
Auxiliary Space: O(h)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

vector<vector<int>> allTraversal(const TreeNode* root){
    vector<int> pre, in, post;
    if(!root) return {pre,in,post};

    stack<pair<const TreeNode*,int>> st;
    st.emplace(root, 1);

    while(!st.empty()){

        auto &current = st.top();

        if(current.second == 1){
            pre.push_back(current.first->data);
            current.second++;
            if(current.first->left) 
                st.emplace(current.first->left,1);
        }else if(current.second == 2){
            in.push_back(current.first->data);
            current.second++;
            if(current.first->right)
                st.emplace(current.first->right,1);
        }else{
            post.push_back(current.first->data);
            st.pop();
        }
    }
    return {pre,in,post};
}