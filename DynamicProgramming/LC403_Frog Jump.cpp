#include<bits/stdc++.h>
using namespace std;

/*
    Problem: LeetCode 403 - Frog Jump

    Approach:
    - DFS + Memoization (Top-down DP).
    - State: dp[i][k] indicates whether the frog can reach the last
      stone starting from the i-th stone with the previous jump length k.
    - From each state, try jumps of:
        k - 1
        k
        k + 1
      (only positive jump lengths are considered).
    - Use a hash map to quickly find whether the next stone exists.

    Time Complexity: O(n²)
    Space Complexity: O(n²)

    Author: Mann Kamble
*/


int solve(vector<vector<int>>&dp,vector<int>& stones,unordered_map<int,int>& index,int i, int lastJump){
    if(dp[i][lastJump]!=-1) return dp[i][lastJump];
    if(i==stones.size()-1) return dp[i][lastJump]=1;
    for(int jump=lastJump-1;jump<=lastJump+1;jump++){
        if(jump<=0) continue;
        auto it=index.find(jump+stones[i]);
        if(it!=index.end()){
            if(solve(dp,stones,index,it->second,jump)) return dp[i][lastJump]=1;
        }
    }
    return dp[i][lastJump]=0;
}
    
bool canCross(vector<int>& stones) {
    int  n=stones.size();
    for (int i = 1; i < n; i++) {
        if (stones[i] - stones[i - 1] > i) return false;
    }
    unordered_map<int,int> index;
    for(int i=0;i<n;i++) index[stones[i]]=i;
    if(index.find(1)==index.end()) return false;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(dp,stones,index,index[1],1)==1;
}