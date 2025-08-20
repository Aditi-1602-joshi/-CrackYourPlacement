class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> subbox[9];


        for(int i=0; i<9; i++){
            for(int j=0;j<9; j++){
                if(board[i][j] == '.') continue;
                int indexsub= (i/3)*3 + j/3;
                if(rows[i].find(board[i][j]) != rows[i].end() ||
                    cols[j].find(board[i][j]) != cols[j].end() ||
                    subbox[indexsub].find(board[i][j]) != subbox[indexsub].end()){
                        return false;
                    }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                subbox[indexsub].insert(board[i][j]);
            }
        }
        return true;
    }
};