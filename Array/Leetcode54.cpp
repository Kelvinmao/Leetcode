class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return {};
        int row=matrix.size(),col=matrix[0].size();
        int up=0,down=row-1,left=0,right=col-1,k=0,i=0;
        vector<int> res(row*col);
        while(1){
            for(i=left;i<=right;i++)
                res[k++]=matrix[up][i];
            if(++up>down)
                break;
            
            for(i=up;i<=down;i++)
                res[k++]=matrix[i][right];
            if(--right<left)
                break;
            
            for(i=right;i>=left;i--)
                res[k++]=matrix[down][i];
            if(--down<up)
                break;
                
            for(i=down;i>=up;i--)
                res[k++]=matrix[i][left];
            if(++left>right)
                break;
        }
        return res;
    }
};
