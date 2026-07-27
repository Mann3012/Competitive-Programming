#include<bits/stdc++.h>
using namespace std;

/*
Insert a node into a Binary Search Tree (Iterative)

Time Complexity:
    O(h), where h is the height of the tree.
    - Average: O(log n)
    - Worst: O(n)

Space Complexity:
    O(1)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

TreeNode* insertNode (TreeNode* root, int key){
    if(!root) return new TreeNode(key);
    TreeNode* curr=root;
    while (true) {
        // Duplicates are inserted into the left subtree.
        if(key <= curr->data){
            if(curr->left){
                curr = curr->left;
            }else{
                curr->left = new TreeNode(key);
                break;
            }
        }else{
            if(curr->right){
                curr = curr->right;
            }else{
                curr->right = new TreeNode(key);
                break;
            }
        }
    }
    return root;
}