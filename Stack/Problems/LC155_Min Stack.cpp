#include<bits/stdc++.h>
using namespace std;


/*
 * LeetCode 155 - Min Stack
 *
 * Idea:
 * Implement the stack using a singly linked list where each node stores:
 *   1. data   -> the actual value
 *   2. minVal -> the minimum value from this node to the bottom of the stack
 *
 * This allows getMin() to return the minimum element in O(1) time without
 * traversing the stack. While pushing a new element, the current minimum is
 * updated using:
 *
 *     min(currentValue, previousMinimum)
 *
 * Time Complexity:
 *   push()   : O(1)
 *   pop()    : O(1)
 *   top()    : O(1)
 *   getMin() : O(1)
 *
 * Space Complexity:
 *   O(n)
 */

class MinStack {
private:
    struct Node{
        int data;
        int minVal;
        Node* next;
        Node(int val,int minimum) : data(val), minVal(minimum), next(nullptr){}
    };
    Node* head=nullptr;
public:
    MinStack() {
    }


    // Free all dynamically allocated nodes.
    ~MinStack() {
        while(head){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    
    void push(int value) {
        if(head==nullptr){
            head=new Node(value,value);
        }else{
            Node* temp=new Node(value,min(value,head->minVal));
            temp->next=head;
            head=temp;
        }
    }
    
    void pop() {
        if(head==nullptr) return;
        Node* temp=head->next;
        delete head;
        head=temp;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return head->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */