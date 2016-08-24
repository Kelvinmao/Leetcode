class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowValid[9][9]={false},colValid[9][9]={false},subBoardValid[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    int k=i/3*3+j/3;/*如果第一格九宫格的编号为0,board[i][j]这个元素存在于第(i/3*3+j/3)个九宫格内*/
                    if(rowValid[i][num]||colValid[j][num]||subBoardValid[k][num])/*如果在未赋值之前就为true,则说明发生了重复*/
                        return false;
                    rowValid[i][num]=colValid[j][num]=subBoardValid[k][num]=true;/*如果未重复，则将其赋值为true*/
                }
            }
        }
        return true;
    }
};
