#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
bool DetectLoop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = false;
        temp = temp->next;
    }
    return false;
}
/*
T.C is O(n)
S.C is O(n)->map is taking space
*/

// *******************************
/*
Floyd cycle detection
T.C is O(n)
S.C is O(1)
*/
node *FloydDetectLoop(node *head) // This function will return intersection in the loop
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return fast;
        }
    }
    NULL;
}
node *GetStartingNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *intersection = FloydDetectLoop(head);
    if(intersection==NULL){
        return NULL;
    }
    node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
// Remove loop
void removeLoop(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *starting = GetStartingNode(head);
    node *temp = starting;
    if(starting==NULL){
        return ;
    }
    while (temp->next != starting)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    return 0;
}