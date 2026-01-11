class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int> st;
        
        for(int i : a){
            st.insert(i);
        }
        for(int i : b){
            st.insert(i);
        }
        
        vector<int> arr;
        for(int i : st){
            arr.push_back(i);
        }
        
        return arr;
    }
};

==============================================================================================================
--------------------------------------------------------------------------------------------------------------
==============================================================================================================

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int m = a.size();
        int n = b.size();
        
        vector<int> arr;
        int i = 0, j = 0;
        
        // merge of merge sort
        while(i<m && j<n){
            // skip duplicate - first array
            if(i>0 && a[i] == a[i-1]){
                i++;
                continue;
            }
            // skip duplicate - second array
            if(j>0 && b[j] == b[j-1]){
                j++;
                continue;
            }
            
            // select and push smaller element
            if(a[i] < b[j]){
                arr.push_back(a[i]);
                i++;
            }
            else if(b[j] < a[i]){
                arr.push_back(b[j]);
                j++;
            }
            // if equal - skip
            else {
                arr.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        // push remaining element - first array
        while(i < m){
            // if element same - skip
            if(i==0 || a[i] != a[i-1]){
                arr.push_back(a[i]);
            }
            i++;
        }
        
        // push remaining element - second array
        while(j < n){
            // if element same - skip
            if(j==0 || b[j] != b[j-1]){
                arr.push_back(b[j]);
            }
            j++;
        }
        
        return arr;
    }
};
