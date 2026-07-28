#include<bits/stdc++.h>
using namespace std;


int solve(string& s,string& p,int i,int j,vector<vector<int>>&dp){
    if(i==-1 && j==-1) return 1;
    if(j==-1) return 0;
    if(i==-1){
        if(j>=1 && p[j]=='*') return solve(s,p,i,j-2,dp);
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[j]=='.'){
        return dp[i][j]=solve(s,p,i-1,j-1,dp);
    }else if(p[j]=='*'){
        int ans=solve(s,p,i,j-2,dp);
        if(p[j-1]==s[i] || p[j-1]=='.') ans|=solve(s,p,i-1,j,dp);
        return dp[i][j]=ans;
    }
    if(s[i]!=p[j]) return dp[i][j]=0;
    return dp[i][j]=solve(s,p,i-1,j-1,dp);
}
bool isMatch(string s, string p) {
    int n=s.size();
    int m=p.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(s,p,n-1,m-1,dp)==1;
}