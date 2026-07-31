#include<bits/stdc++.h>
using namespace std;

long long MOD=1000000007;
    
int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    vector<int> nextSmaller(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        if(st.empty()){
            nextSmaller[i]=n;
        }else{
            nextSmaller[i]=st.top();
        }
        st.push(i);
    }
    vector<int> prevSmaller(n);
    stack<int> st2;
    for(int i=0;i<n;i++){
        while(!st2.empty() && arr[st2.top()]>=arr[i]) st2.pop();
        if(st2.empty()){
            prevSmaller[i]=-1;
        }else{
            prevSmaller[i]=st2.top();
        }
        st2.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long left=1LL*(nextSmaller[i]-i);
        long long right=1LL*(i-prevSmaller[i]);
        ans=(ans + (1LL*arr[i]*left*right)%MOD)%MOD;
    }
       
    return (int)ans;
}