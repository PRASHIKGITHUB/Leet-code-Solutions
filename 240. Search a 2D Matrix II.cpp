class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int rowIndex=0;
        int colIndex=col-1;

        while(rowIndex<row && colIndex>=0){ //here we are going to increase row or decrease column thus we get this condition inside while loo;
            int element=matrix[rowIndex][colIndex];
            if(element==target){
                return 1;
            }
            else if(target>element){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
        
    }
};