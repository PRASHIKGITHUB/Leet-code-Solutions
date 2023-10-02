#include <bits/stdc++.h>
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
void convertIntosortedDLL(Node* root,Node*&head){
    //base case
    if(root==NULL){
        return;
    }

    convertIntosortedDLL(root->right,head);

    root->right=head;

    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntosortedDLL(root->left,head);
}
using namespace std;

int main()
{
    return 0;
}