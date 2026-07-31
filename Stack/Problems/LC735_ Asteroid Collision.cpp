#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 735 - Asteroid Collision

Approach:
Traverse the asteroids from right to left while maintaining a stack of
surviving asteroids to the right of the current position.

A collision is possible only when the current asteroid is moving right
(positive) and the top of the stack is moving left (negative).

Collision cases:
1. Equal sizes: both asteroids explode.
2. Current asteroid is larger: destroy the top asteroid and continue
   checking the current asteroid against the next survivor.
3. Top asteroid is larger: current asteroid explodes.

Since the traversal is from right to left, popping the stack naturally
produces the surviving asteroids in the correct left-to-right order.

Time Complexity: O(n)
Space Complexity: O(n)
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    stack<int> st;
    int i=n-1;
    while(i>=0){
        if(st.empty() || st.top()>0 || asteroids[i]<0){
            st.push(asteroids[i]);
        }else{
            if(abs(st.top())==abs(asteroids[i])){
                st.pop();
            }else if(abs(st.top())<abs(asteroids[i])){
                st.pop();
                continue;
            }
        }
        i--;
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}