class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowValid[9][9]={false},colValid[9][9]={false},subBoardValid[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    int k=i/3*3+j/3;/*�����һ��Ź���ı��Ϊ0,board[i][j]���Ԫ�ش����ڵ�(i/3*3+j/3)���Ź�����*/
                    if(rowValid[i][num]||colValid[j][num]||subBoardValid[k][num])/*�����δ��ֵ֮ǰ��Ϊtrue,��˵���������ظ�*/
                        return false;
                    rowValid[i][num]=colValid[j][num]=subBoardValid[k][num]=true;/*���δ�ظ������丳ֵΪtrue*/
                }
            }
        }
        return true;
    }
};
