#include <bits/stdc++.h> 
using namespace std;
//T.C->O(n^n)
//S.C->O(n)

void addSolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
	vector<int>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int>>&board,int n){
	int x=row;
	int y=col;
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}

	x=row;
	y=col;

	//check for diagonal
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
		x--;
	}

	x=row;
	y=col;
	while(x<=n-1 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
		x++;
	}
	return true;
}
void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
	//base 
	if(col==n){
		addSolution(board,ans,n);
		return;

	}

	//Solve 1 case and rest Recursion will take care
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			//if placing the queen is safe
			board[row][col]=1;
			solve(col+1,ans,board,n);
			//backTracking
			board[row][col]=0;
		}
	}
	
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;
	solve(0,ans,board,n);
	return ans;
	
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&777
//According to sir it should be optimised but it is not

#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n, unordered_map<int, bool> &rowmap, unordered_map<int, bool> &downDia, unordered_map<int, bool> &upDia)
{
    if (rowmap[row])
    {
        return false;
    }
    if (downDia[row + col])
    {
        return false;
    }
    if (upDia[n - 1 + col - row])
    {
        return false;
    }
    return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, unordered_map<int, bool> &rowmap, unordered_map<int, bool> &downDia, unordered_map<int, bool> &upDia)
{
    // base
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    // Solve 1 case and rest Recursion will take care

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n, rowmap, downDia, upDia))
        {
            // if placing the queen is safe
            board[row][col] = 1;
            rowmap[row] = 1;
            downDia[row + col] = 1;
            upDia[n - 1 + col - row] = 1;
            solve(col + 1, ans, board, n, rowmap, downDia, upDia);
            // backTracking
            board[row][col] = 0;
            rowmap[row] = 0;
            downDia[row + col] = 0;
            upDia[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    unordered_map<int, bool> rowmap;
    unordered_map<int, bool> downDia;
    unordered_map<int, bool> upDia;
    vector<vector<int>> ans;
    solve(0, ans, board, n, rowmap, downDia, upDia);
    return ans;
}