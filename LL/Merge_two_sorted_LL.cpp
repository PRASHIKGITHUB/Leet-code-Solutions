#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
Node<int>* solve(Node<int>* first,Node<int>* second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    Node<int>*curr1=first;
    Node<int>* curr2=second;
    Node<int>* next1=first->next;
    Node<int>* next2=curr1->next;

    while(next1!=NULL && curr2!=NULL){
        if(curr2->data<=next1->data && curr2->data>=curr1->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
            
        }
        else{
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL){
        return second;
    }
    else if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        return solve(first,second);

    }
    else{
        return solve(second ,first);
    }
}
int main(){
    return 0;
}