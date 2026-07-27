#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr){}
};

class Stack{
    private:
        ListNode*  head;
        int sz;
    
    public:
        Stack(){
            sz=0;
            head=nullptr;
        }

        void push(int val){
            ListNode* node= new ListNode(val);
            node->next=head;
            head=node;
            sz++;
        }

        int top() const {
            if(head==nullptr)
                throw runtime_error("Stack is empty");
            return head->data;
        }

        void pop(){
            if(head==nullptr)
                return;
            
            ListNode* next=head->next;
            delete head;
            head=next;
            sz--;
        }
        int size() const {
            return sz;
        }

        bool empty() const {
            return sz==0;
        }

};

