#include<bits/stdc++.h>
using namespace std;


/*
Problem: Vertical Order Traversal of a Binary Tree
LeetCode: 987

Approach:
BFS with coordinates (column, row).
Store nodes as:
column -> row -> multiset

Time Complexity: O(n log n)
Auxiliary Space: O(n)
*/

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

vector<vector<int>> verticalOrderTraversal(const TreeNode* root){
    map<int, map<int, multiset<int>>> nodes;

    queue<pair<const TreeNode*, pair<int, int>>> q;
    if(root) q.push({root, {0, 0}});

    while(!q.empty()){
        auto [node,position]=q.front();
        q.pop();

        auto [x,y]=position;

        nodes[x][y].insert(node->data);

        if(node->left){
            q.push({node->left, {x-1, y+1}});
        }
        if(node->right){
            q.push({node->right, {x+1, y+1}});
        }
    }
    vector<vector<int>> verticalOrder;
    for( const auto &column:nodes){
        vector<int> col;
        for(const auto &row:column.second){
            col.insert(col.end(), row.second.begin(), row.second.end());
        }
        verticalOrder.push_back(col);
    }
    return verticalOrder;
}