/*Complete the function below*/

class Solution {
  private:
    bool isPalindrome(int n) {
        // code here.
        string str = to_string(n);
        
        int i = 0;
        int j = str.length()-1;
        
        bool isPalindrome = true;
        
        while(i <= j){
            if(str[i] != str[j]){
                isPalindrome = false;
            }
            i++;
            j--;
        }
        
        return isPalindrome;
    }
    
  public:
    bool isPalinArray(vector<int> &arr) {
        // code here
        int result = true;
        
        for(auto element : arr){
            result = result && isPalindrome(element);
        }
        
        return result;
    }
};
