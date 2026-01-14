class Solution {
private:
    // helper function addSolution - build ans array using board array 
    void addSolution(vector<vector<int>> &board, int n, vector<vector<string>> &ans){
        vector<string> temp;

        for(int i=0; i<n; i++){

            string rowLine = "";    //store row values

            for(int j=0; j<n; j++){
                if(board[i][j] == 1){
                    rowLine.push_back('Q');
                }
                else rowLine.push_back('.');
            }
            temp.push_back(rowLine);
        }

        ans.push_back(temp);
    }

    // [helper func] isSafe - check index safe or not for placing queen
    // not safe index =>
    // same row index - board[row][i]
    //  same col index - board[i][col]
    // same diagonal index - |i - j| = |row - col| or |i + j| = |row + col|
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        // Common mistakes to avoid
        //     ❌ Checking right side (no queens exist there yet)
        //     ❌ Scanning entire board (O(n²))
        //     ❌ Checking same column (you control column placement)

        // Check same row on the left
        for(int j = 0; j < col; j++) {
            if(board[row][j] == 1)
                return false;
        }

        // Check upper-left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }

        // Check lower-left diagonal
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j] == 1)
                return false;
        }

        return true;
    }

    // solve helper func - arranges all queen in board so that no two queen can attack each other
    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n){
        // base case
        if(col == n){
            addSolution(board, n, ans);
            return;
        }

        // solve 1 case and rest recursion will take care
        for(int row=0; row<n; row++){
            if( isSafe(row, col, board, n) ){ //check if placing queen safe or not
                board[row][col] = 1;
                solve(col+1, ans, board, n);    //recursive relation
                board[row][col] = 0;    //backtracking (remove queen from this index/place of the board)
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        // edge/base case
        if(n == 1){
            ans.push_back({"Q"});
            return ans;
        }

        solve(0, ans, board, n);

        return ans;
    }
};
