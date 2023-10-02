#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *reverse(node *start)
{
    node *curr = start;
    node *prev = NULL;
    node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
node *Middle(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    }
    return slow;
}
bool isPalindrome(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    // step-1:find middle node
    node *middle = Middle(head);

    // step-2:reverse after middle node
    node *temp = reverse(middle->next);
    middle->next = temp;

    // step-3:compare two halves
    node *head1 = head;
    node *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step-4:repeat step 2
    middle->next = reverse(middle->next);
    return true;
}
int main()
{

    return 0;
}