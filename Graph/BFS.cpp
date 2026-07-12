#include<bit/stdc++.h>
using namespace std;

/*
Algorithm: Breadth First Search (BFS)

Time Complexity:
O(V + E)

Space Complexity:
O(V)

Applications:
1. Shortest path in an unweighted graph
2. Connected components
3. Level-order traversal
4. Bipartite graph checking
5. Multi-source BFS
*/

vector<int> bfsTraversal(int src,vector<vector<int>>&adj){
    int n=adj.size();
    vector<int> order;
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        order.push_back(node);
        for(int adjNode:adj[node]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push(adjNode);
            }
        }
    }
    return bfsTraversal;
}

pair<vector<int>,vector<int>> bfsDistance(int src,const vector<vector<int>>&adj){
    int n=adj.size();
    vector<int> parent(n,-1);
    vector<int> dist(n,INT_MAX);
    queue<int> q;
    dist[src]=0;
    q.push(src);
    parent[src]=src;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int nxt:adj[node]){
            if(dist[nxt]==INT_MAX){
                parent[nxt]=node;
                dist[nxt]=dist[node]+1;
                q.push(nxt);
            }
        }
    }
    return {parent,dist};
}

vector<int> bfsPath(int src,int dest,const vector<vector<int>>&adj){
    int n=adj.size();
    vector<int> parent(n,-1);
    parent[src]=src;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int adjNode:adj[node]){
            if(parent[adjNode]==-1){
                parent[adjNode]=node;
                q.push(adjNode);
            }
        }
    }
    if(parent[dest]==-1) return {};
    vector<int> path;
    int curr=dest;
    path.push_back(curr);
    while(parent[curr]!=curr){
        curr=parent[curr];
        path.push_back(curr);
    }
    reverse(path.begin(),path.end());
    return path;
}