/*solution1 264ms*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int row=0,col=matrix[0].size()-1,size=matrix.size();
        while(row<size&&col>=0){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                col--;
            else if(matrix[row][col]<target)
                row++;
        }
        return false;
    }
};

/*solution2 164ms*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = row-1,j =0;
        while(i>=0&&j<col){
            if(target>matrix[i][j])
                j++;
            else if(target<matrix[i][j])
                i--;
            else
                return true;
        }
        return false;
    }
};
