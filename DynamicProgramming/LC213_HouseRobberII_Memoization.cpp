#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 213 - House Robber II

Approach:
- Since the houses form a circle, we cannot rob both
  the first and the last house.
- Solve two linear House Robber problems:
    1. Houses [0 ... n-2]
    2. Houses [1 ... n-1]
- Return the maximum of the two.

Time Complexity: O(n)
Space Complexity: O(n)
*/


int robHelper(vector<int>& const nums,int index,int high,vector<int>&dp){
        if(index>high) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans=nums[index]+robHelper(nums,index+2,high,dp);
        ans=max(ans,robHelper(nums,index+1,high,dp));
        return dp[index]=ans;
    }
    int solve(vector<int>& const nums,int low,int high){
        int n=nums.size();
        vector<int> dp(n,-1);
        return robHelper(nums,low,high,dp);
    }
    
    int rob(vector<int>& const nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }