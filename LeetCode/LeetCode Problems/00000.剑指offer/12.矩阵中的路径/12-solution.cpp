class Solution {
public:
    bool res = false;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
                    dfs(i, j, visited, word, 1, board);
                    if (res) return res;
                }
            }
        } 
        return res;
    }

    void dfs(int i, int j, vector<vector<bool>> &visited, string &word, int idx, vector<vector<char>> &board) {
        if (idx == word.size() || res) {
            res = true;
            return ;
        }
        //cout << board[i][j] << endl;
        visited[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y] || word[idx] != board[x][y]) continue;
            dfs(x, y, visited, word, idx + 1, board);
            visited[x][y] = false;
        }
    }
};