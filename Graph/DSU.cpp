#include<bits/stdc++.h>
using namespace std;


/*
Disjoint Set Union (Union Find)

Operations:
- find()
- unionByRank()
- unionBySize()
- isConnected()
- getSize()

Time Complexity:
find()             O(alpha(N))
unionByRank()      O(alpha(N))
unionBySize()      O(alpha(N))

Space Complexity:
O(N)

Applications:
- Connected Components
- Kruskal's MST
- Dynamic Connectivity
- Number of Provinces
*/

class DSU{
    private:
        vector<int> parent,size,rank;
    public:
        DSU(int n){
            parent.resize(n);
            size.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
                rank[i]=0;
            }
        }
        int find(int i){
            if(parent[i]!=i){
                parent[i]=find(parent[i]);
            }
            return parent[i];
        }

        void unionByRank(int u,int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv) return ;
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }else if(rank[pv]<rank[pu]){
                parent[pv]=pu;
            }else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u,int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv) return;
            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
        int getSize(int u){
            return size[find(u)];
        }

        bool isConnected(int u,int v){
            return find(u)==find(v);
        }

};