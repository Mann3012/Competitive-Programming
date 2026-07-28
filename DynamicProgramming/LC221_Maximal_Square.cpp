#include<bits/stdc++.h>
using namespace std;

/*
    Problem: LeetCode 221 - Maximal Square

    Approach:
    - Bottom-up Dynamic Programming.
    - dp[i][j] stores the side length of the largest square of '1's
      with its bottom-right corner at cell (i, j).
    - Transition:
        If matrix[i][j] == '1':
            dp[i][j] = 1 + min({
                dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1]
            })
        Otherwise:
            dp[i][j] = 0
    - Initialize the first row and first column separately, as they
      cannot be extended from previous cells.
    - The answer is the maximum square area (side × side).

    Time Complexity: O(n * m)
    Space Complexity: O(n * m)

    Author: Mann Kamble
*/



int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(matrix[0][j]=='1'){
                dp[0][j]=1;
                ans=1;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    ans=max(ans,dp[i][j]*dp[i][j]);
                }
            }
        }
        return ans;
    }