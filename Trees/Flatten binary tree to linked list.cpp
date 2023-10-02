#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
//s.c->O(1)
//t.c->O(n)
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                Node* pred=curr->left;
                while(pred->right!=NULL){
                    pred=pred->right;
                }
                
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};