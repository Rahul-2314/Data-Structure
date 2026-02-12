class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        // int m = mat[0].size();
        
        // step 1 : reverse each row
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        
        // step 2: transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[j][i], mat[i][j]);
            }
        }
    }
};
