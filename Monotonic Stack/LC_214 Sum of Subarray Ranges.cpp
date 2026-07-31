#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 2104 - Sum of Subarray Ranges

Approach:
Use monotonic stacks to count how many subarrays each element is the
maximum and minimum of.

For each nums[i]:
Contribution = nums[i] × (maxCount - minCount)

where

maxCount = (i - prevLarger[i]) * (nextLarger[i] - i)
minCount = (i - prevSmaller[i]) * (nextSmaller[i] - i)

Different comparison operators are used while finding previous/next
greater and smaller elements to handle duplicate values correctly.

Time Complexity: O(n)
Space Complexity: O(n)
*/

long long subArrayRanges(vector<int>& nums) {
    int n=nums.size();
    vector<int> nextSmaller(n);
    vector<int> nextLarger(n);
    stack<int> st1;
    stack<int> st2;
    for(int i=n-1;i>=0;i--){
        while(!st1.empty() && nums[st1.top()] >= nums[i]) st1.pop();
        while(!st2.empty() && nums[st2.top()] <= nums[i]) st2.pop();
        
        nextSmaller[i]= st1.empty() ? n : st1.top();
        nextLarger[i]= st2.empty() ? n :st2.top();
        st1.push(i);
        st2.push(i);
    }

    vector<int> prevSmaller(n);
    vector<int> prevLarger(n);
    stack<int> st3;
    stack<int> st4;
    for(int i=0;i<n;i++){
        while(!st3.empty() && nums[st3.top()] > nums[i]) st3.pop();
        while(!st4.empty() && nums[st4.top()] < nums[i]) st4.pop();

        prevSmaller[i]=st3.empty()?-1:st3.top();
        prevLarger[i]=st4.empty()?-1:st4.top();

        st3.push(i);
        st4.push(i);
    }

    long long ans=0;

    for(int i=0;i<n;i++){
        int maxCount=(nextLarger[i]-i)*(i-prevLarger[i]);
        int minCount=(nextSmaller[i]-i)*(i-prevSmaller[i]);
        ans+=(1LL*nums[i]*(maxCount-minCount));
    }
    return ans;
}