// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        int lastIndex = arr[n-1];   //store lastIndex
        
        for(int i=n-1; i>=0; i--){
            if(i == 0){
                arr[i] = lastIndex; //first index = original last-Index
            }
            else {
                arr[i] = arr[i-1];  // shift elements
            }
        }
    }
};
