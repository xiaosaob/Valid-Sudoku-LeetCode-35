// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > blks(9, vector<bool>(9, false));
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] >= '1' && board[i][j] <= '9') {
                    int num = board[i][j] - '1';
                    if(rows[i][num]) return false;
                    rows[i][num] = true;
                    if(cols[j][num]) return false;
                    cols[j][num] = true;
                    if(blks[3*(i/3)+j/3][num]) return false;
                    blks[3*(i/3)+j/3][num] = true;
                }
            }
        }
        return true;
    }
};
