#include<bits/stdc++.h>
using namespace std;
void SortedInsert(stack<int> &stack,int a){
	if(stack.empty()){
		stack.push(a);
	}
	else if(stack.top()<a){
		stack.push(a);
	}
	else{
		int b=stack.top();
		stack.pop();
		SortedInsert(stack,a);
		stack.push(b);
	}
	return;
}