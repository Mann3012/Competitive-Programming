#include<bits/stdc++.h>
using namespace std;

/*
 * LeetCode 174 - Dungeon Game
 *
 * Idea:
 * DP from bottom-right to top-left.
 * dp[j] stores the minimum health required to ENTER the current cell
 * in the current row so that the knight can safely reach the princess.
 *
 * Transition:
 * dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j])
 *
 * Space Optimization:
 * Since each state depends only on the cell to the right and the cell below,
 * the 2D DP table is compressed into a 1D array.
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n=dungeon.size();
    int m=dungeon[0].size();
    vector<int> dp(m);
    dp[m-1]=max(1,1-dungeon[n-1][m-1]);
    for(int j=m-2;j>=0;j--) dp[j]=max(1,dp[j+1]-dungeon[n-1][j]);
    for(int i=n-2;i>=0;i--){
        dp[m-1]=max(1,dp[m-1]-dungeon[i][m-1]);
        for(int j=m-2;j>=0;j--) dp[j]=max(1,min(dp[j+1],dp[j])-dungeon[i][j]);
    }
    return dp[0];
}