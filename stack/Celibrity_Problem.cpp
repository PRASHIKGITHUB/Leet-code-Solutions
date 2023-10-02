#include <bits/stdc++.h> 
using namespace std;
// T.C->O(n)
// T.C->O(n)
// You can do this in more optimized way

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> s;
	 //step 1: push all peoples
	 for(int i=0;i<n;i++){
		 s.push(i);
	 }

	//step 2: select two and compare them
	 while(s.size()>1){
		 int a=s.top();
		 s.pop();
		 int b=s.top();
		 s.pop();
		 if(knows(a,b)){
			 s.push(b);
		 }
		 else{
			 s.push(a);
		 }
	 }

	//step 3:single element in stack is a potential member
	//so verify it	

	int ans=s.top();
	int zerocount=0;
	int onecount=0;
	for(int i=0;i<n;i++){
		if(i!=ans && knows(ans,i)==0){
			zerocount++;
		}
	}
	for(int i=0;i<n;i++){
		if(i!=ans && knows(i,ans)==1){
			onecount++;
		}
	}
	if(zerocount==n-1 && onecount==n-1){
		return ans;
	}
	else{
		return -1;
	}
}