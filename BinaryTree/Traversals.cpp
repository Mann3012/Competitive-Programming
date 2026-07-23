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
vector<vector<int>> levelOrderTraversal(const Node* root){
    if(!root) return {};
    vector<vector<int>> levelOrder;
    queue<const Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        vector<int> currLevel;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            currLevel.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        levelOrder.push_back(currLevel);
    }
    return levelOrder;
}


vector<int> inorderIterative(const Node* root){
    vector<int> ans;
    if(!root) return ans;
    const Node* node=root;
    stack<const Node*> st;
    while(!st.empty() || node){
        if(node){
            st.push(node);
            node=node->left;
        }else{
            const Node* temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            node=temp->right;
        }
    }
    return ans;
}
vector<int> preOrderIterative(const Node* root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<const  Node*> st;
        st.push(root);
        while(!st.empty()){
            const Node* node=st.top();
            st.pop();
            ans.push_back(node->data);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
}
vector<int> postOrderIterative(const Node* root) {
        // code here
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<const Node*> st;
    st.push(root);
    while(!st.empty()){
        const Node*  node=st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> postOrderIterativeOneStack(const Node* root) {

    vector<int> ans;
    if (root == nullptr) return ans;

    stack<const Node*> st;
    const Node* node = root;

    while (!st.empty() || node != nullptr) {

        // Keep moving to the leftmost node.
        // Push every node on the path so we can return later.
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        }
        else {

            // We have reached the end of a left chain.
            // Now check whether the current node has a right subtree.
            const Node* temp = st.top()->right;

            if (temp == nullptr) {

                // No right subtree exists.
                // Both left and right are done, so visit this node.
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                // After visiting a node,
                // it may be the right child of its parent.
                // If yes, then the parent's entire subtree
                // is also finished, so visit the parent too.
                while (!st.empty() && st.top()->right == temp) {

                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else {

                // Right subtree has not been processed yet.
                // Move to the right subtree.
                node = temp;
            }
        }
    }

    return ans;
}

vector<vector<int>> allTraversal(const Node* root){
    vector<int> pre,in,post;
    if(!root) return {pre,in,post};
    stack<pair<const Node*,int>> st;
    st.emplace(root,1);
    while(!st.empty()){
        auto &it = st.top();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            if(it.first->left) st.emplace(it.first->left,1);
        }else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            if(it.first->right)st.emplace(it.first->right,1);
        }else{
            post.push_back(it.first->data);
            st.pop();
        }
    }
    return {pre,in,post};
}


vector<vector<int>> verticalOrderTraversal(const Node* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<const Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        const Node* node=it.first;
        int x=it.second.first;
        int y=it.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            q.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for( const auto &p:nodes){
        vector<int> col;
        for(const auto &q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

vector<int> morrisInorderTraversal(Node* root){
    vector<int> inorder;
    Node* curr=root;
    while(curr){
        if(!curr->left){
            inorder.push_back(curr->data);
            curr=curr->right;
        }else{
            Node* pred=curr->left;
            while(pred->right && pred->right!=curr){
                pred=pred->right;
            }
            if(!pred->right){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=nullptr;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
}