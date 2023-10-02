#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


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


int getLength(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
        return;
    }

    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
        return;
    }

    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}


void insertAtPosition(node *&tail, node *&head, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    (temp->next)->prev = nodeToInsert;
    temp->next = nodeToInsert;
}


void deleteAtPosition(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int i = 1;
    node *current = head;
    node *previous = NULL;
    while (i < position)
    {
        previous = current;
        current = current->next;
        i++;
    }
    if (current->next == NULL)
    {
        current->prev = NULL;
        previous->next = NULL;
        delete current;
        tail = previous;
        return;
    }
    current->prev = NULL;
    previous->next = current->next;
    current->next = NULL;
    delete current;
}

void reverse(node*&head,node*&tail){
    node* ptr1=head;
    node* ptr2=head->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    //first node gets reversed
    while (ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    
    
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = head;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head, tail, 33);
    print(head);
    insertAtHead(head, tail, 12);
    print(head);
    insertAtHead(head, tail, 8);
    print(head);
    insertAtTail(head, tail, 67);
    print(head);
    insertAtTail(head, tail, 25);
    print(head);
    insertAtPosition(tail, head, 100, 3);
    print(head);
    insertAtPosition(tail, head, 1, 1);
    print(head);
    insertAtPosition(tail, head, 102, 9);
    print(head);
    deleteAtPosition(head,tail,1);
    print(head);
    deleteAtPosition(head,tail,8);
    print(head);
    deleteAtPosition(head,tail,3);
    print(head);
    insertAtTail(head,tail,22);
    print(head);
    reverse(head,tail);
    print(head);
    return 0;
}