class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i][num] > 0)
                    return false;

                if (col[j][num] > 0)
                    return false;

                if (box[boxIndex][num] > 0)
                    return false;

                row[i][num]++;
                col[j][num]++;
                box[boxIndex][num]++;
            }
        }

        return true;
    }
};