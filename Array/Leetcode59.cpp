class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(!n)
            return {};
        vector<vector<int>> res(n,vector<int>(n, 0));/*初始化的时候要仔细考虑，第一次submission因为初始化导致了RTE*/
        int up=0,down=n-1,left=0,right=n-1,i=0,j=0,k=0,num=1;
        while(true){
            for(k=left;k<=right;k++){
                res[up][k]=num;
                num+=1;
            }
            if(++up>down)
                break;
            for(k=up;k<=down;k++){
                res[k][right]=num;
                num+=1;
            }
            if(--right<left)
                break;
            for(k=right;k>=left;k--){
                res[down][k]=num;
                num+=1;
            }
            if(--down<up)
                break;
            for(k=down;k>=up;k--){
                res[k][left]=num;
                num+=1;
            }
            if(++left>right)
                break;
        }
        return res;
    }
};
