class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row*col;


        int startingrow=0;
        int startingcol=0;
        int endingrow=row-1;
        int endingcol=col-1;

        while(count<total){
            for(int col=startingcol;count<total && col<=endingcol;col++){
                ans.push_back(matrix[startingrow][col]);
                count++;
            }
            startingrow++;

            for(int row=startingrow;count<total && row<=endingrow;row++){
                ans.push_back(matrix[row][endingcol]);
                count++;
            }
            endingcol--;

            for(int col=endingcol;count<total && col>=startingcol;col--){
                ans.push_back(matrix[endingrow][col]);
                count++;
            }
            endingrow--;

            for(int row=endingrow;count<total && row>=startingrow;row--){
                ans.push_back(matrix[row][startingcol]);
                count++;
            }
            startingcol++;

        }
        return ans;
    }
};