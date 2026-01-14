class Solution {
    // is safe - check if a inedx is safe to move or not
    // for this we require index properties -
    // x < n, y < n, visited == 0?, maze[x]==1?, n = size of maze;
    bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>>& maze, int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && maze[x][y]==1 && visited[x][y]==0){
            return true;
        }
        else return false;
    }
    
    void solve(int x, int y, vector<vector<int>>& maze, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
        //   base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
    
        // 4 movements - D, L, R, U (lexicographically smallest order)
        
        visited[x][y] = 1;  //mark current index - visited
        
        // down
        if( isSafe(x + 1, y, visited, maze, n)){
            // recursive call for next - updated index
            solve(x+1, y, maze, n, ans, visited, path + 'D');   //update path
        }
        // left
        if( isSafe(x, y - 1, visited, maze, n)){
            solve(x, y-1, maze, n, ans, visited, path + 'L');
        }
        // right
        if( isSafe(x, y + 1, visited, maze, n)){
            solve(x, y+1, maze, n, ans, visited, path + 'R');
        }
        // up
        if( isSafe(x - 1, y, visited, maze, n)){
            solve(x-1, y, maze, n, ans, visited, path + 'U');
        }
        
        visited[x][y] = 0;  //when backtracking, make index, visited = false
    }
  
  
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        int n = maze.size();
        
        vector<string> ans;
        vector<vector<bool>> visited (n, vector<bool>(n, 0));
        
        string path = "";
        
        // edge/base case - if maze starting index value is zero(0) -> no need for checking
        if(maze[0][0] == 0){
            return ans;
        }
        
        solve(0, 0, maze, n, ans, visited, path);
        
        return ans;
    }
};
