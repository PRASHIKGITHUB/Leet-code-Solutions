#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    void insertAtTail(struct Node*&anshead,struct Node*&anstail,struct Node* curr){
        if(anshead==NULL){
            anshead=curr;
            anstail=curr;
        }
        else{
        anstail->next=curr;
        anstail=curr;
            
        }
        return;
    }
    struct Node *add(Node* first,Node* second){
        Node*anshead=NULL;
        Node*anstail=NULL;
        int carry=0;
        int sum=0;
        int digit=0;
        while(first!=NULL && second!=NULL){
            sum=first->data+second->data+carry;
            carry=sum/10;
            digit=sum%10;
            Node* curr=new Node(digit);
            insertAtTail(anshead,anstail,curr);
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
            sum=first->data+carry;
            carry=sum/10;
            digit=sum%10;
            Node* curr=new Node(digit);
            insertAtTail(anshead,anstail,curr);
            first=first->next;
        }
        while(second!=NULL){
            sum=second->data+carry;
            carry=sum/10;
            digit=sum%10;
            Node* curr=new Node(digit);
            insertAtTail(anshead,anstail,curr);
            second=second->next;
        }
        while(carry!=0){
            sum=carry;
            digit=sum%10;
            carry=sum/10;
            struct Node* curr=new struct Node(digit);//this works too*************************
            insertAtTail(anshead,anstail,curr);
        }
        return anshead;
        
    }
    struct Node* reverse(Node* head){
        Node*curr=head;
        Node*prev=NULL;
        Node* forward=head->next;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reverse two ll
        first=reverse(first);
        second=reverse(second);
        //add two ll
        Node* ans=add(first,second);
        
        ans=reverse(ans);
        return ans;
    }
};
int main(){
    return 0;
}