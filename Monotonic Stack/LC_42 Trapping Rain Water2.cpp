#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 42 - Trapping Rain Water(Two Pointer Approach)

Idea:
Maintain two pointers at the left and right ends of the array along with
the maximum height seen so far from both directions (lMax and rMax).

At each step:
- If height[left] <= height[right], the left side is guaranteed to have
  a right boundary at least as tall as height[left]. Therefore, the water
  trapped at the current left index depends only on lMax.
  Water trapped = lMax - height[left].
  Update lMax and move the left pointer.

- Otherwise, the right side is guaranteed to have a left boundary at least
  as tall as height[right]. Therefore, the water trapped at the current
  right index depends only on rMax.
  Water trapped = rMax - height[right].
  Update rMax and move the right pointer.

Each index is processed exactly once.

Time Complexity: O(n)
Space Complexity: O(1)
*/


int trap(vector<int>& height) {
    int n=height.size();
    int lMax,rMax,total;
    lMax=0;
    rMax=0;
    total=0;
    int l=0;
    int r=n-1;
    while(l<r){
        if(height[l]<=height[r]){
            lMax=max(lMax,height[l]);
            total+=(lMax-height[l]);
            l++;
        }else{
            rMax=max(rMax,height[r]);
            total+=(rMax-height[r]);
            r--;
        }
    }
    return total;
}