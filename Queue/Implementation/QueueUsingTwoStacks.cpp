#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        stack<int> st1;
        stack<int> st2;
        void transfer(){
            if(st2.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
        }
    public:
        Queue(){}
        void push(int x){
            st1.push(x);
        }

        int peek(){
            if (empty())
                throw runtime_error("Queue is empty");
            transfer();
            return st2.top();
        }

        int pop(){
            if (empty())
                throw runtime_error("Queue is empty");
            transfer();
            int y=st2.top();
            st2.pop();
            return y;
        }

        bool empty() const {
            return st1.empty() && st2.empty();
        }

        int size() const {
            return st1.size() + st2.size();
        }
};