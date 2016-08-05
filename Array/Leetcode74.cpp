/*solution1 
Traverse the 2D matrix*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int i=0,j=0;
        int row=matrix.size(),col=matrix[0].size();
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(matrix[i][j]==target)
                    return true;
        return false;
    }
};

/*solution2
use binary-search in rows*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int row=matrix.size(),i=0;
        int low=0,size=matrix[0].size(),high=size-1,mid=0;
        for(i=0;i<row;i++){
            low=0;
            high=size-1;
            while(low<=high){
                mid=low+(high-low)/2;
                if(matrix[i][mid]==target)
                    return true;
                if(matrix[i][mid]<target)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};

/*solution3*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int low=0,size=matrix.size(),high=size-1,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        int row=high;
        
        if(row<0)
            return false;
        low=0;
        high=matrix[0].size()-1;
        mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[row][mid]==target)
                return true;
            if(matrix[row][mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};

