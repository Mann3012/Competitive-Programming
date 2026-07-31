#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 496 - Next Greater Element I

Approach:
1. Traverse nums2 from right to left while maintaining a monotonic decreasing stack.
2. For each element:
   - Remove all smaller or equal elements from the stack.
   - The top of the stack (if any) is the next greater element.
   - Store this mapping in a hash map.
3. Answer each query in nums1 in O(1) using the hash map.

Time Complexity: O(n + m)
    n = nums2.size(), m = nums1.size()

Space Complexity: O(n)
    Hash map + monotonic stack.
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    unordered_map<int,int> mp;
    stack<int> st;
    for(int i = n-1; i>= 0; i--){
        while( !st.empty() && st.top() <= nums2[i] ) st.pop();
        if( st.empty() ){
            mp[nums2[i]] =- 1;
        }else{
            mp[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> ans(nums1.size());
    for(int i=0; i < nums1.size(); i++) ans[i] = mp[nums1[i]];
    return ans;
}
