class Solution {
public:
    //col[i][n] = true表示第i行有一个为n的数，cell[i][j][n]表示第i行第j列个cell有一个为n的数
    bool col[9][10], row[9][10], cell[3][3][10];
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '0';
                if (row[i][n] || col[j][n] || cell[i / 3][j / 3][n] ) return false;
                row[i][n] = col[j][n] = cell[i / 3][j / 3][n] = 1;
            }
        }
        return true;
    }
};