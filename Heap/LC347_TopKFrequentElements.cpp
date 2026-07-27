#include <bits/stdc++.h>
using namespace std;


/*
LeetCode 347 - Top K Frequent Elements

Approach:
- Count the frequency of each element using a hash map.
- Store (frequency, element) pairs in a max heap.
- Extract the top k elements.

Time Complexity: O(n + m log m)
Space Complexity: O(m)

where m = number of unique elements.
*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for (int num : nums)
        freq[num]++;

    priority_queue<pair<int, int>> pq;

    for (auto [num, count] : freq)
        pq.push({count, num});

    vector<int> ans;

    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}