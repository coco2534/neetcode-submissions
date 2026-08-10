class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, int> row[9];
        unordered_map<int, int> col[9];
        unordered_map<int, int> box[9];

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                // Find which 3x3 box this cell belongs to
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check row
                if (row[i].find(num) != row[i].end())
                    return false;

                // Check column
                if (col[j].find(num) != col[j].end())
                    return false;

                // Check box
                if (box[boxIndex].find(num) != box[boxIndex].end())
                    return false;

                // Add number to row, column and box
                row[i][num]++;
                col[j][num]++;
                box[boxIndex][num]++;
            }
        }

        return true;
    }
};