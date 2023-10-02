#include <bits/stdc++.h>
using namespace std;
//S.C->O(1)
//T.C->O(9^m) where m is empty cells
bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    int n = board[0].size();
    for (int i = 0; i < n; i++)
    {
        // check row
        if (board[row][i] == val)
        {
            return false;
        }
        // check column
        if (board[i][col] == val)
        {
            return false;
        }

        // 3*3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, board, val))
                    {
                        board[i][j] = val;

                        // revursive calls
                        bool ageSolutions = solve(board);
                        if (ageSolutions)
                        {
                            return true;
                        }
                        else
                        {
                            // back track
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
int main(){
    vector<vector<int>>arr(9,vector<int>(9,0));
    // for (int  i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin>>arr[i][j];
    //     }
        
    // }
    solveSudoku(arr);
    cout<<endl;
    for (int  i = 0; i < 9; i++)
    {
        for (int  j = 0; j < 9; j++)
        {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }
    
    
    return 0;
}