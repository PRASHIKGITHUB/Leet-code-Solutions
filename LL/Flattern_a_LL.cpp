Node* merge(Node* first,Node* second){
	if(first==NULL){
		return second;
	}
	else if(second==NULL){
		return first;
	}
	Node* result;
	if(first->data < second->data){
		result=first;
		result->child=merge(first->child,second);
	}
	else{
		result=second;
		result->child=merge(first,second->child);
	}
	result->next=NULL;
	return result;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	else{
		return merge(head,flattenLinkedList(head->next));
	}
}