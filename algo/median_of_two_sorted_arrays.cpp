class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // keep track of indexes of both the array
        int i = 0, j = 0;
        
        // store middle and second middle element
        int m1 = -1;
        int m2 = -1;
        
        for(int count=0; count<=(n+m)/2; count++){
            m2 = m1;
            
            if(i != n && j != m){
                m1 = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
            }
            else if(i < n){
                m1 = nums1[i++];
            }
            else {
                m1 = nums2[j++];
            }
        }
        
        if( (m+n) % 2 != 0){
            return m1;
        }
        else {
            return (m1 + m2) / 2.0;
        }
    }
};
