#include <bits/stdc++.h> 
using namespace std;
void solve(string str,int i,string result,vector<string>&ans){
if(i>=str.length()){
	if(result.length()==0){ //no need to add empty string in ans
		return;
	}
	ans.push_back(result);
	return;

}

solve(str,i+1,result,ans);

char element=str[i];
result.push_back(element);
solve(str,i+1,result,ans);


}
vector<string> subsequences(string str){
	
	int index=0;
	vector<string>ans;
	string result;
	solve(str,0,result,ans);
	return ans;

	
}
