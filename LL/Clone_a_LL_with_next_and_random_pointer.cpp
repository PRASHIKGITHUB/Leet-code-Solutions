//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// Approach-2
//S.C->O(n)
//T.C->O(n)
class Solution
{
    public:
    void insertAtTail(Node*&head,Node*&tail,int data){
        Node* temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        return;
    }
    Node *copyList(Node *head)
    {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* originalhead=head;
        while(originalhead!=NULL){
            insertAtTail(clonehead,clonetail,originalhead->data);
            originalhead=originalhead->next;
        }
        
        //create a Map
        unordered_map<Node*,Node*> OldtoNewNode;
        originalhead=head;
        Node* cloneheadcopy=clonehead;
        while(originalhead!=NULL){
            OldtoNewNode[originalhead]=cloneheadcopy;
            originalhead=originalhead->next;
            cloneheadcopy=cloneheadcopy->next;
        }
        
        //mapping random pointer
        originalhead=head;
        cloneheadcopy=clonehead;
        while(originalhead!=NULL){
            cloneheadcopy->arb=OldtoNewNode[originalhead->arb];
            cloneheadcopy=cloneheadcopy->next;
            originalhead=originalhead->next;
        }
        
        return clonehead;
    }

};

//{ Driver Code Starts. ****************************




// } Driver Code Ends
//Approach-2
////S.C->O(1)
//T.C->O(n)
class Solution
{
    public:
    void insertAtTail(Node*&head,Node*&tail,int data){
        Node* temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        return;
    }
    Node *copyList(Node *head)
    {
        //1.create a clone list
        Node* clonehead=NULL;
        Node* clonetail=NULL; 
        Node * temp=head;
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        //2.clonenodes add them in between original list
        Node * originalNode=head;
        Node* cloneNode=clonehead; 
        while(cloneNode!=NULL && originalNode!=NULL){
            
        Node* next=originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;
        
        next=cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
        }
        //3.copy random pointers
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
               temp->next->arb=temp->arb?temp->arb->next:temp->arb;
            }
            temp=temp->next->next;
        }
        
        //4.revert changes done in step 2
        originalNode=head;
        cloneNode=clonehead;
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        //5.return ans
        return clonehead;
        
        
    }

};

//{ Driver Code Starts.


