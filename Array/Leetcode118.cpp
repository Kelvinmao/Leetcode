class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> val;
        val.resize(numRows);
        int i=0,j=0;
        for(i=0;i<numRows;i++){
            val[i].resize(i+1);
            val[i][0]=1;
            val[i][val[i].size()-1]=1;
            for(j=1;j<val[i].size()-1;j++)
                val[i][j]=val[i-1][j-1]+val[i-1][j];
        }
        return val;
    }
};

