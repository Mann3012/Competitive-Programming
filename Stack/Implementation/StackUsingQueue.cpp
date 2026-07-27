#include<bits/stdc++.h>
using namespace std;

/*
Stack using a single queue

push : O(n)
pop  : O(1)
top  : O(1)
size : O(1)
*/

class Stack{
    private:
        queue<int> q;
    public:

        void push(int val){
            size_t sz=q.size();
            q.push(val);
            // Push element to the back and rotate the queue
            // so the newly inserted element becomes the front.
            // Thus, pop() and top() become O(1).
            for(size_t i=0;i<sz;i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
            if(q.empty()) return;
            q.pop();
        }

        int top() const {
            if(q.empty())
                throw runtime_error("Stack is empty");
            return q.front();
        }

        int size() const {
            return q.size();
        }

        bool empty() const {
            return q.empty();
        }

};