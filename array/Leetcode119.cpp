class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i=0,j=0;
        vector<vector<int>> val;
        val.resize(rowIndex+1);
        for(i=0;i<=rowIndex;i++){
            val[i].resize(i+1);
            val[i][0]=1;
            val[i][val[i].size()-1]=1;
            for(j=1;j<val[i].size()-1;j++)
                val[i][j]=val[i-1][j-1]+val[i-1][j];
        }
        return val[rowIndex];
    }
    
};

