#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        next = NULL;
    }
};
// S.C-> O(n)
// T.C-> O(n)
Node *sortList(Node *head)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }
    return head;
}
// better approach
// S.C->O(1)
// T.C->O(n)
void insert(Node *&zerotial, Node *temp)
{
    zerotial->next = temp;
    zerotial = temp;
}
Node *sortList(Node *head)
{
    Node *zerohead = new Node();
    Node *zerotail = zerohead;
    Node *onehead = new Node();
    Node *onetail = onehead;
    Node *twohead = new Node();
    Node *twotail = twohead;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            insert(zerotail, curr);
        }
        else if (curr->data == 1)
        {
            insert(onetail, curr);
        }
        else if (curr->data == 2)
        {
            insert(twotail, curr);
        }

        curr = curr->next;
    }
    // merge 3 sublist

    // 1st list is not empty
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;
    // setup head
    head = zerohead->next;

    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}
int main()
{
    return 0;
}