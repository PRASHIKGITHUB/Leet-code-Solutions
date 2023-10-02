#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *next;
    int data;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertNode(node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        tail->next = tail;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found-> curr is representing element wala node
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non empty

        // assuming that "value" is present in the Linked list
        node *prev = tail;
        node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 Node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        //>=2 nODE LINKED LIST
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
void print(node *tail)
{

    node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
// #############################################3
bool isCircular(node *head)
{
    node *temp = head->next;
    if (head == NULL)
    {
        return true;
    }
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ###############################################333 
int main()
{
    node *tail = NULL;
    // empty list me insert krre hai
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 7, 16);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    cout << isCircular(tail) << endl;
    return 0;
}