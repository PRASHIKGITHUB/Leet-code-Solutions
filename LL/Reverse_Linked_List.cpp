#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // ~node()
    // {
    // }
};

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        head = temp;
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
    // cout << head->data << endl;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        head = temp;
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&tail, node *&head, int data, int n)
{
    if (n == 1)
    {

        insertAtHead(head, tail, data);
        return;
    }

    node *temp = head;
    int i = 1;
    while (i < n - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // creating a node to insert data
    node *NodetoInset = new node(data);
    NodetoInset->next = temp->next;
    temp->next = NodetoInset;
}

void deleteAtPosition(node *&tail, node *&head, int position)
{
    // start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
        return;
    }

    node *current = head;
    node *prev = NULL;
    int i = 1;
    while (i < position)
    {
        prev = current;
        current = current->next;
        i++;
    }
    // tail needs to update before deleting last node
    if (current->next == NULL)
    {
        prev->next = current->next;
        tail = prev;
        current->next = NULL;
        delete current;
        return;
    }

    prev->next = current->next;
    current->next = NULL;
    delete current;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(node *&head)
{
    if (head==NULL || head->next==NULL)
    {
        return;
    }
    
    node *current = head;
    node *prev = NULL;
    node *forward;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
}
void solve(node*&head,node*prev,node*curr){
    if (curr==NULL)
    {
        head=prev;
        return;
    }
    node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    head=prev;
    solve(head,prev,curr);
    
}
void reverseRecursion(node* &head){
    if (head==NULL || head->next==NULL)
    {
        return; 
    }
    
    node* prev=NULL;
    node* curr=head;
    solve(head,prev,curr);
    return;
}
int main()
{
    node *node1 = new node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    node *head = node1;
    node *tail = node1;
    insertAtPosition(tail, head, 1, 1);
    print(head);
    insertAtPosition(tail, head, 5, 3);
    print(head);
    insertAtPosition(tail, head, 8, 4);
    print(head);
    deleteAtPosition(tail, head, 4);
    print(head);
    insertAtTail(head, tail, 90);
    print(head);
    deleteAtPosition(tail, head, 1);
    print(head);
    reverseRecursion(head);
    print(head);
    return 0;
}