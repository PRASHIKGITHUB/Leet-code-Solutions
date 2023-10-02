#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *UniqueSortedList(node *&head)
{
    node *curr = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (curr != NULL) 
    {
        if (curr->next!=NULL && curr->data == curr->next->data)
        {
            node* next_next=curr->next->next;
            node* node_to_delete=curr->next;
            delete node_to_delete;
            curr->next=next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
}
int main()
{
    return 0;
}