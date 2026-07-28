#include<bits/stdc++.h>
using namespace std;

/*
Subarray Sum Equals K

Approach:
- Prefix Sum + Hash Map
- Store the frequency of each prefix sum.
- If (currentPrefixSum - k) has appeared before,
  then there exists a subarray with sum k.

Time Complexity: O(n)
Space Complexity: O(n)
*/

int subarraySum(const  vector<int>& nums, int k){
    unordered_map<int,int> prefixFreq;
    prefixFreq[0]=1;
    int prefixSum=0;
    int count=0;
    for(int number : nums){
        prefixSum+=number;
        auto it=prefixFreq.find(prefixSum-k);
        if(it != prefixFreq.end()) count+=it->second;
        prefixFreq[prefixSum]++;
    }
    return count;
}