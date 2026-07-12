#include<bits/stdc++.h>
using namespace std;

/*
Algorithm: Topological Sort (Kahn's Algorithm)

Time Complexity: O(V + E)

Space Complexity: O(V)

Returns:
A topological ordering of the graph.
If the returned vector has size < V, the graph contains a cycle.

Applications:
- Course Schedule
- Dependency Resolution
- DAG Problems
- Detecting Cycles in Directed Graphs
*/

// Returns one valid topological ordering.
// If the returned vector has size < n, the graph contains a cycle.
vector<int> kahnTopologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int nxt : adj[node]) {
            indegree[nxt]--;

            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    return topo;
}


// Returns true if the directed graph contains a cycle.
bool hasDirectedCycle(const vector<vector<int>> &adj){
    int n=adj.size();
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(int adjNode:adj[i]) indegree[adjNode]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(int adjNode:adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0) q.push(adjNode);
        }
    }
    return cnt!=n;
}