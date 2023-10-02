#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
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
int getLength(node *head)
{
    int count = 0;
    node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
node *returnPointer(node *head)
{
    int n = (getLength(head) / 2) + 1;
    node *temp = head;
    while (--n)
    {
        temp = temp->next;
        // cout<<temp->data<<" ";
    }
    return temp;
}
node *optimised(node *head)
{
    node *slow = head;
    node *fast = head->next;
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    else if (fast->next == NULL)
    {
        return fast;
    }

    while (fast != NULL && fast->next!=NULL)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
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
    insertAtPosition(tail, head, 69, 4);
    print(head);

    // insertAtTail(head, tail, 90);
    print(head);
    // cout<<getLength(head)<<endl;
    // cout<<returnPointer(head)->data<<endl;
    cout << endl << optimised(head)->data << endl;

    return 0;
}