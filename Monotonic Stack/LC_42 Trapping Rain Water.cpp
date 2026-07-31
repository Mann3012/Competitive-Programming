#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 42 - Trapping Rain Water

Approach:
1. Precompute the maximum height to the right of every index.
2. Traverse from left to right while maintaining the maximum height seen so far.
3. The water trapped at each index equals:
      min(leftMax, rightMax) - height[i]
4. Sum the trapped water over all indices.

Time Complexity: O(n)
Space Complexity: O(n)
*/



int trap(vector<int>& height) {
    int n=height.size();
    vector<int> suffMax(n);
    suffMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--) suffMax[i]=max(height[i],suffMax[i+1]);
    int trappedWater=0;
    int prefMax=0;
    for(int i=0;i<n;i++){
        prefMax=max(prefMax,height[i]);
        trappedWater+=(min(suffMax[i],prefMax)-height[i]);
    }
    return trappedWater;
}
